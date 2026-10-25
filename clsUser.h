#pragma once
#include<iostream>
#include"clsPerson.h"
#include<vector>
#include"clsString.h"
#include<fstream>
#include"clsDate.h"
#include"clsUtil.h"
using namespace std;

class clsUser :public clsPerson
{

private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password = "";
    short _Permissions = 0;
    bool _MarkedForDelete = false;
    short _EncryptionKey = 3;
    struct stLoginRegisterRecord;

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "","","","","",  0);
    }

    static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return  clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4],clsUtil::DecryptText( vUserData[5]), stoi(vUserData[6]));
    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += clsUtil::EncryptText( User.Password) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }


    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLineToUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

     string _PrepareLogInRecord(string Seperator = "#//#")
    {
        string LoginRecord = "";

        LoginRecord += clsDate::GetSystemDateTimeString()+Seperator;
        LoginRecord += UserName+Seperator;
        LoginRecord += clsUtil::EncryptText(Password) +Seperator;
        LoginRecord+=  to_string(Permissions);

        return LoginRecord;
    }


    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line,string Seperator = "#//#")
     {
         stLoginRegisterRecord LoginRegisterRecord;
         vector <string> vLoginRegisterDataLine = clsString::Split(Line,Seperator);

         LoginRegisterRecord.DateTime = vLoginRegisterDataLine[0];
         LoginRegisterRecord.UserName = vLoginRegisterDataLine[1];
         LoginRegisterRecord.Password = clsUtil::DecryptText( vLoginRegisterDataLine[2]);
         LoginRegisterRecord.Permissions = stoi(vLoginRegisterDataLine[3]);

         return LoginRegisterRecord;
     }

    

     
     static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser &User : vUsers)
            {
                if (User.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete. 
                    DataLine = _ConverUserObjectToLine(User);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& User : _vUsers)
        {
            if (User.UserName == GetUserName())
            {
               // _Password = clsUtil::EncryptText(_Password, _EncryptionKey);
                User = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {
        //_Password = clsUtil::EncryptText(_Password, _EncryptionKey);
        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }


public:

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32,
        pManageUsers = 64,pShowLoginRegister=128
    };
    clsUser(enMode Mode,string FirstName,string LastName,string Email,string Phone
        ,string UserName,string Password,short Permissions):
        clsPerson(FirstName,LastName,Email,Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;

    }

    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password = "";
        short Permissions = 0;

    };



     bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }



    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    string GetUserName()
    {
        return _UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;


    void SetPassword(string Password) 
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(short Permissions)
    {
        _Permissions = Permissions;
    }

    short GetPermissions()
    {
        return _Permissions;
    }

    __declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUsernameExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(UserName))
            {
                return enSaveResults::svFaildUsernameExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }



    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    static clsUser Find(string UserName)
    {


        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName,string Password)
    {


        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName&&User.Password==Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    static bool IsUserExist(string UserName,string Password)
    {
        clsUser User = clsUser::Find(UserName,Password);
        return (!User.IsEmpty());
    }


    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& User : _vUsers)
        {
            if (User.UserName == _UserName)
            {
                User._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    bool CheckAccesssPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if ((this->Permissions & Permission) == Permission)
            return true;
        else
            return false;
    }

    void RegisterLogIn()
    {
        string stDataLine =_PrepareLogInRecord() ;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }


    static vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecords;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;
            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {

                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecords.push_back(LoginRegisterRecord);
            }

            MyFile.close();

        }

        return vLoginRegisterRecords;
    }

};

