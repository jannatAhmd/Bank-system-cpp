#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsDepositScreen:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient& Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber() 
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number? ";
        cin >> AccountNumber;

        return AccountNumber;
    }

public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t  Deposit Screen");

        string AccountNumber = _ReadAccountNumber();
       
       while (!clsBankClient::IsClientExist(AccountNumber))
        {
           cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
           AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease Enter Deposit Amount? ";
        Amount = clsInputValidate<double>::ReadPositiveNumber("\nInvalid Amount,Please Enter deposit amount? ");

        char Answer = 'n';
        cout << "\nAre you sure you want to perform this transaction? y/n ? ";
        cin >> Answer;

        if (Answer=='y'||Answer=='Y')
        {
            Client.Deposit(Amount);
            cout << "\nAmount Deposited Succsessfully.\n";
            cout << "\nNew Balance is: " << Client.AccountBalance<<endl;
        }
        else
        {
            cout << "\nOperation Was cancelled.\n";
        }

    }

};

