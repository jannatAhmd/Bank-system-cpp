#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

class clsManageUsersScreen:protected clsScreen
{
private:
    enum enManageUsersMenueOptions
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eShowMainMenue = 6
    };

    static short ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

   static void _GoBackToManageUsersMenue()
    {

        cout << "\n\nPress any key to continue... \n";
        system("pause>0");
        ShowManageUsersMenue();
    }

   static void _ShowListUsersScreen()
   {
      // cout << "\nList Users Will Be Here...\n";
       clsUsersListScreen::ShowUsersList();
   }

   static void _ShowAddNewUserScreen() 
   {
       //cout << "\nAdd Users Will Be Here...\n";
       clsAddNewUserScreen::ShowAddNewUserScreen();
   }

   static void _ShowDeleteUserScreen()
   {
       //cout << "\nDelete User Will Be Here...\n";
       clsDeleteUserScreen::ShowDeleteUserScreen();
   }

   static void _ShowUpdateUserScreen()
   {
       //cout << "\nUpdate User Will Be Here...\n";
       clsUpdateUserScreen::ShowUpdateUserScreen();
   }

   static void _ShowFindUserScreen()
   {
       //cout << "\nFind User Will Be Here...\n";
       clsFindUserScreen::ShowFindUserScreen();
   }

   static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
   {
       switch (ManageUsersMenueOption)
       {
       case enManageUsersMenueOptions::eListUsers:
       {
           system("cls");
           _ShowListUsersScreen();
           _GoBackToManageUsersMenue();
           break;
       }
       case enManageUsersMenueOptions::eAddNewUser:
       {
           system("cls");
           _ShowAddNewUserScreen();
           _GoBackToManageUsersMenue();
           break;
       }
       case enManageUsersMenueOptions::eDeleteUser:
       {
           system("cls");

           _ShowDeleteUserScreen();
           _GoBackToManageUsersMenue();
           break;
       }
       case enManageUsersMenueOptions::eUpdateUser:
       {
           system("cls");
           _ShowUpdateUserScreen();
           _GoBackToManageUsersMenue();
           break;
       }
       case enManageUsersMenueOptions::eFindUser:
       {
           system("cls");
           _ShowFindUserScreen();
           _GoBackToManageUsersMenue();
           break;
       }
       case enManageUsersMenueOptions::eShowMainMenue:
       {
           
       }

       }

   }

public:

    static void ShowManageUsersMenue()
    {
        if (!CheckAccessRights(clsUser::pManageUsers))
        {
            return;
            // this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t  Manage Users Screen.");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" <<  "\t\t  Manage Users Screen \n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "[1] List Users.\n";
        cout << setw(37) << left << "" << "[2] Add New User.\n";
        cout << setw(37) << left << "" << "[3] Delete User.\n";
        cout << setw(37) << left << "" << "[4] Update User.\n";
        cout << setw(37) << left << "" << "[5] Find User.\n";
        cout << setw(37) << left << "" << "[6] Main Menue.\n";
        
        cout << setw(37) << left << "" << "===========================================\n";


        _PerformManageUsersMenueOption(enManageUsersMenueOptions(ReadManageUsersMenueOption()));
    }


};

