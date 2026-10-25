#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsCurrencyCalculatorScreen: protected clsScreen
{
private:

	static float _ReadAmount()
	{
		float Amount = 0;
		cout << "\nEnter Amount To Exchange: ";
		Amount = clsInputValidate<float>::ReadPositiveNumber();

		 return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency,string Title="Currency Card: ")
	{
		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _PrintCalculationsResults(float Amount,clsCurrency Currency1, clsCurrency Currency2)
	{
		float AmountInUSD = 0;

		if (Currency1.CurrencyCode() != "USD")
		{
			_PrintCurrencyCard(Currency1, "Convert From");

			AmountInUSD = Currency1.ConvertToUSD(Amount);

			cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = ";
			cout << AmountInUSD << " " << "USD\n";
		}

		if (Currency2.CurrencyCode() != "USD")
		{
			cout << "\nConverting From USD to:\n";
			cout << "\nTo:\n";
			_PrintCurrencyCard(Currency2);

			float AmountInCurrrency2 = Currency2.ConvertFromUSD(AmountInUSD);

			cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = ";
			cout << AmountInCurrrency2 << " " << Currency2.CurrencyCode()<<endl;
		}

	}

	static clsCurrency _GetCurrency(string message)
	{
		string CurrencyCode = "";
		cout << message;
		CurrencyCode = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	
public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue='y';
		do
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 Code: ");

			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, Currency1, Currency2);

			cout << "\n\nDo You want to perform another Calculation? ";
			cin >> Continue;

		}while(Continue=='y'||Continue=='Y');
	}
};

