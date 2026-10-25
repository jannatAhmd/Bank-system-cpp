#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsAddNewUserScreen:protected clsScreen
{
private:
    
    static int _ReadPermissionsToSet()
    {
        /* cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');*/

        char Answer = 'n';
        int permission = 0;

        cout << "\nDo you want to give full access? y/n ";
        cin >> Answer;

        if (Answer == tolower('y'))
            return -1;

        else
        {
            cout << "\nDo you want to give access to: \n";

            cout << "\nShow Client list? y/n ";
            cin >> Answer;
            if (Answer == tolower('y'))
                permission += (clsUser::enPermissions::pListClients);

            cout << "\nAdd new Client? y/n ";
            cin >> Answer;
            if (Answer == tolower('y'))
                permission |= (clsUser::enPermissions::pAddNewClient);

            cout << "\nDelete Client? y/n ";
            cin >> Answer;
            if (Answer == tolower('y'))
                permission |= (clsUser::enPermissions::pDeleteClient);

            cout << "\nUpdate Client? y/n ";
            cin >> Answer;
            if (Answer == tolower('y'))
                permission |= (clsUser::enPermissions::pUpdateClients);

            cout << "\nFind Client? y/n ";
            cin >> Answer;
            if (Answer == tolower('y'))
                permission |= (clsUser::enPermissions::pFindClient);

            cout << "\nTransactions? y/n ";
            cin >> Answer;
            if (Answer == tolower('y'))
                permission |= (clsUser::enPermissions::pTranactions);

            cout << "\nManage users? y/n ";
            cin >> Answer;
            if (Answer == tolower('y'))
                permission |= (clsUser::enPermissions::pManageUsers);

            cout << "\nLogin register? y/n ";
            cin >> Answer;
            if (Answer == tolower('y'))
                permission |= (clsUser::enPermissions::pShowLoginRegister);

        }

        int setAllPermissionsManually = clsUser::enPermissions::pListClients |
            clsUser::enPermissions::pAddNewClient | clsUser::enPermissions::pDeleteClient |
            clsUser::enPermissions::pUpdateClients | clsUser::enPermissions::pFindClient |
            clsUser::enPermissions::pTranactions | clsUser::enPermissions::pManageUsers |
            clsUser::enPermissions::pShowLoginRegister;

        if (permission == setAllPermissionsManually)
            return -1;

        return permission;
    }

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate<string>::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate<string>::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate<string>::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate<string>::ReadString();
 
        cout << "\nEnter Password: ";
        User.Password = clsInputValidate<string>::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card   :";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " <<User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }


public:
    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t  Add New User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate<string>::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate<string>::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);


        _ReadUserInfo(NewUser);


        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUsernameExists:
        {
            cout << "\nError User was not saved because User name is used!\n";
            break;

        }
        }
    }


};

