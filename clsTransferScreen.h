#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include "clsBankClient.h"
#include"clsUser.h"
#include"clsDate.h"

class clsTransferScreen : protected clsScreen
{
private:
	
	static string _ReadAccountNumber(string message="")
	{
		string AccountNumber;
		cout << message;
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number was not exists, Enter another one: ";
			AccountNumber = clsInputValidate<string>::ReadString();

		}
		return AccountNumber;

	}

	static void _PrintClient(clsBankClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static double _ReadTransferAmount(clsBankClient& SenderClient)
	{
		double Amount = 0;
		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate<double>::ReadPositiveNumber("\nInvalid Amount,Please Enter Transfer amount? ");

		while (Amount > SenderClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available balance, Enter another amount? ";
			Amount = clsInputValidate<double>::ReadPositiveNumber("\nInvalid Amount,Please Enter Transfer amount? ");

		}

		return Amount;
	}


public:
	static void ShowTransferScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Transfer Screen");

		clsBankClient SourceClient =
			clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer From: "));

		_PrintClient(SourceClient);

		clsBankClient DestinationClient =
			clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer To: "));

		_PrintClient(DestinationClient);

		double Amount = _ReadTransferAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this transaction? y/n ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\ntransfer done succsesfully.\n";
			}
			else
				cout << "\ntransfer Failed.\n";
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

