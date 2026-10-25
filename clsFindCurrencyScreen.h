#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include<iomanip>
#include"clsString.h"

class clsFindCurrencyScreen : protected clsScreen
{

private:


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

	static void _ShowResults(clsCurrency& Currency)
	{
		
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found:-) \n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency NOT Found:-) \n";

		}
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		
		cout << "\n\nFind By: [1] Code or [2] Country ? ";
		short Answer = clsInputValidate<short>::ReadNumberBetween(1, 2);

		switch (Answer)
		{
		case 1:
		{
			cout << "\nPlease Enter currency code: ";
			string CurrencyCode = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
			break;
		}

		case 2:
		{
			cout << "\nPlease Enter Country Name: ";
			string CountryName = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
			_ShowResults(Currency);
			break;
		}

		}
	}
};

