#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsUpdateCurrencyRate : protected clsScreen
{
private :

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

	static float _ReadRate()
	{
		float NewRate = 0;
		cout << "\nEnter New Rate: ";
		NewRate = clsInputValidate<float>::ReadPositiveNumber();

		return NewRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t Update Currency Screen");

		string CurrencyCode="";
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency code is not found, choose another one: ";
			CurrencyCode = clsInputValidate<string>::ReadString();

		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		cout << "\nAre you sure you want to update this Currency y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:\n";
			cout << "______________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Updated successfully :-)\n";
			_PrintCurrency(Currency);
		}
	}
};

