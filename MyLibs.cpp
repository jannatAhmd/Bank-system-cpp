// MyLibs.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsMAinScreen.h"
#include"clsLogInScreen.h"
#include "clsCurrency.h"

// update client lesson

//void ReadClientInfo(clsBankClient& Client)
//{
//    cout << "\nEnter FirstName: ";
//    Client.FirstName = clsInputValidate::ReadString();
//
//    cout << "\nEnter LastName: ";
//    Client.LastName = clsInputValidate::ReadString();
//
//    cout << "\nEnter Email: ";
//    Client.Email = clsInputValidate::ReadString();
//
//    cout << "\nEnter Phone: ";
//    Client.Phone = clsInputValidate::ReadString();
//
//    cout << "\nEnter PinCode: ";
//    Client.PinCode = clsInputValidate::ReadString();
//
//    cout << "\nEnter Account Balance: ";
//    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
//}

//void UpdateClient()
//{
//    string AccountNumber = "";
//
//    cout << "\nPlease Enter client Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//
//    while (!clsBankClient::IsClientExist(AccountNumber))
//    {
//        cout << "\nAccount number is not found, choose another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//
//    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
//    Client1.Print();
//
//    cout << "\n\nUpdate Client Info:";
//    cout << "\n____________________\n";
//
//
//    ReadClientInfo(Client1);
//
//    clsBankClient::enSaveResults SaveResult;
//
//    SaveResult = Client1.Save();
//
//    switch (SaveResult)
//    {
//    case  clsBankClient::enSaveResults::svSucceeded:
//    {
//        cout << "\nAccount Updated Successfully :-)\n";
//        Client1.Print();
//        break;
//    }
//    case clsBankClient::enSaveResults::svFaildEmptyObject:
//    {
//        cout << "\nError account was not saved because it's Empty";
//        break;
//
//    }
//
//    }
//}



// add new client lesson

//void AddNewClient()
//{
//    string AccountNumber = "";
//
//    cout << "\nPlease Enter Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//    while (clsBankClient::IsClientExist(AccountNumber))
//    {
//        cout << "\nAccount Number Is Already Used, Choose another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//
//    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
//
//
//    ReadClientInfo(NewClient);
//
//    clsBankClient::enSaveResults SaveResult;
//
//    SaveResult = NewClient.Save();
//
//    switch (SaveResult)
//    {
//    case  clsBankClient::enSaveResults::svSucceeded:
//    {
//        cout << "\nAccount Addeded Successfully :-)\n";
//        NewClient.Print();
//        break;
//    }
//    case clsBankClient::enSaveResults::svFaildEmptyObject:
//    {
//        cout << "\nError account was not saved because it's Empty";
//        break;
//
//    }
//    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
//    {
//        cout << "\nError account was not saved because account number is used!\n";
//        break;
//
//    }
//    }
//}

//void DeleteClient()
//{
//    string AccountNumber = "";
//
//    cout << "\nPlease Enter Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//
//    while (!clsBankClient::IsClientExist(AccountNumber))
//    {
//        cout << "\nAccount number is not found, Enter another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//
//    clsBankClient Client = clsBankClient::Find(AccountNumber);
//
//    char Answer = 'n';
//    cout << "\nAre you sure you want to delete this Client? ";
//    cin >> Answer;
//
//    if (tolower(Answer)=='y')
//    {
//        if (Client.Delete())
//        {
//            cout << "\nClient Deleted successfully :-) ";
//            Client.Print();
//        }
//        else
//        {
//            cout << "\nError,Client Was not deleted :-( ";
//        }
//    }
//}

//void PrintClientRecordLine(clsBankClient &Client) 
//{
//    cout << "| " << left << setw(15) <<Client.AccountNumber();
//    cout << "| " << left << setw(20) << Client.FullName();
//    cout << "| " << left << setw(12) << Client.Phone;
//    cout << "| " << left << setw(20) << Client.Email;
//    cout << "| " << left << setw(10) << Client.PinCode;
//    cout << "| " << left << setw(12) << Client.AccountBalance;
//
//}

// void ShowAllClients()
//{
//
//
//     vector <clsBankClient> vCleints = clsBankClient::GetClientsList();
//
//    cout << "\n\t\t\t\t Clients List (" << vCleints.size() << ") Cleint (s). ";
//
//    cout << "\n________________________________________________________";
//    cout << "________________________________________\n\n";
//
//    cout << "| " << left << setw(15) << "Accout Number";
//    cout << "| " << left << setw(20) << "Client Name";
//    cout << "| " << left << setw(12) << "Phone";
//    cout << "| " << left << setw(20) << "Email";
//    cout << "| " << left << setw(10) << "Pin Code";
//    cout << "| " << left << setw(12) << "Balance";
//
//    cout << "\n________________________________________________________";
//    cout << "________________________________________\n\n";
//
//
//    if (vCleints.size() == 0)
//    {
//        cout << "\n No clients available in the system.\n";
//
//    }
//    else
//    {
//
//        for (clsBankClient& C : vCleints)
//        {
//            PrintClientRecordLine(C);
//            cout << endl;
//        }
//    }
//    
//    cout << "\n________________________________________________________";
//    cout << "________________________________________\n\n";
//
//
//}

 //show total balances

 void PrintClientRecordBalanceLine(clsBankClient Client)
 {
     cout << "| " << std::left << setw(15) << Client.AccountNumber();
     cout << "| " << std::left << setw(40) << Client.FullName();
     cout << "| " << std::left << setw(12) << Client.AccountBalance;

 }

 void ShowTotalBalances()
 {
     vector <clsBankClient> vClients = clsBankClient::GetClientsList();

     cout << "\n\t\t\t\t Clients List (" << vClients.size() << ") Cleint (s). ";

     cout << "\n_______________________________________________________";
     cout << "_________________________________________\n" << endl;

     cout << "| " << std::left << setw(15) << "Account Number";
     cout << "| " << std::left << setw(40) << "Client Name";
     cout << "| " << std::left << setw(12) << "Balance";
     cout << "\n_______________________________________________________";
     cout << "_________________________________________\n" << endl;

     float TotalBalances = clsBankClient::GetTotalBalances();

     if (vClients.size() == 0)
     {
         cout << "\n No clients available in the system.\n";

     }
     else
     {

         for (clsBankClient& C : vClients)
         {
             PrintClientRecordBalanceLine(C);
             cout << endl;
         }
     }
     
     cout << "\n_______________________________________________________";
     cout << "_________________________________________\n" << endl;
     cout << "\n\t\t\t\t Total Balances = " << TotalBalances << endl ;
     cout << "\n\t\t\t\t( " << clsUtil::NumberToText(TotalBalances) << ")\n";
 }


 static void _PrintCurrency(clsCurrency Currency)
 {
     cout << "\nCurrency Card:\n";
     cout << "_____________________________\n";
     cout << "\nCountry    : " << Currency.Country();
     cout << "\nCode       : " << Currency.CurrencyCode();
     cout << "\nName       : " << Currency.CurrencyName();
     cout << "\nRate(1$) = : " << Currency.Rate();

     cout << "\n_____________________________\n";

 }



int main()
{
    //Currency
    /*clsCurrency Currency1 = Currency1.FindByCode("jod");

    if (Currency1.IsEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        _PrintCurrency(Currency1);
    }

    clsCurrency Currency2 = Currency2.FindByCountry("egg");

    if (Currency2.IsEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
        _PrintCurrency(Currency2);

    }
    else
    {
        _PrintCurrency(Currency2);
    }*/


    while(true)
    {
       
        if (!clsLogInScreen::ShowLogInScreen())
            break;

    }


    //clsMainScreen::ShowMainMenue();

    //7 Main Meneu

    //6 show all balances
   // ShowTotalBalances();

    //5 list Clients
    //ShowAllClients();

    //4 delete client
    //DeleteClient();


    //3 Add new 
   // AddNewClient();

    //2 update 
    // UpdateClient();

    //1 find 

   /* clsBankClient Client1 = clsBankClient::Find("A101");
    if (!Client1.IsEmpty())
    {
        cout << "\nClient Found :-)\n";
    }
    else
    {
        cout << "\nClient Was not Found :-(\n";
    }

    Client1.Print();

    clsBankClient Client2 = clsBankClient::Find("A101", "1234");
    if (!Client2.IsEmpty())
    {
        cout << "\nClient Found :-)\n";
    }
    else
    {
        cout << "\nClient Was not Found :-(\n";
    }
    Client2.Print();


    cout << "\nIs Client Exist? " << clsBankClient::IsClientExist("A101");*/





   // system("pause>0");
    return 0;
}