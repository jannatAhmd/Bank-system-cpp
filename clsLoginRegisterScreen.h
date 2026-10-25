#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsLoginRegisterScreen:protected clsScreen
{
private:
    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << left << setw(35) << LoginRegisterRecord.DateTime;
        cout << "| " << left << setw(20) << LoginRegisterRecord.UserName;
        cout << "| " << left << setw(20) <<LoginRegisterRecord.Password;
        cout << "| " << left << setw(100) << LoginRegisterRecord.Permissions;
    }

public:

    static void ShowLoginRegisterScreen()
    {
        if (!CheckAccessRights(clsUser::pFindClient))
        {
            return;
            // this will exit the function and it will not continue
        }

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::GetLoginRegisterList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegisterRecords.size()) + ") Records(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLoginRegisterRecords.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord & Record : vLoginRegisterRecords)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

