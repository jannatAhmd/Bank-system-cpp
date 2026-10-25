#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include"Global.h"

class clsLogInScreen:protected clsScreen
{
private:
    static  bool _Login()
    {
        bool LoginFaild = false;
        string Username, Password;
        short FaildLoginCount = 0;
        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " << (3-FaildLoginCount) << " Trials to login.\n\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\n\nYou are locked after 3 failed trials.\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);
            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);


        CurrentUser.RegisterLogIn();
         clsMainScreen::ShowMainMenue();
         return true;


    }

public:

    static bool ShowLogInScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return  _Login();
        
    }

};

