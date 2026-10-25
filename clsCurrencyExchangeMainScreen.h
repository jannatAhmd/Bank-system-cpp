#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen :protected clsScreen
{
private:

    enum enCurrenciesMainMenueOptions
    {
        eListCurrencies=1,eFindCurrency=2,eUpdateCurrencyRate=3,
        eCurrencyCalculator=4,eMainMenue=5
    };

    static short _ReadCurrenciesMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToCurrenciesMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowCurrenciesMenue();
    }

    static void _ShowCurrenciesListScreen()
    {
        //cout << "\nCurrencies List Screen Will be here...\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
       // cout << "\nFind Currency Screen Will be here...\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        //cout << "\nUpdate Currency Screen Will be here...\n";
        clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();

    }

    static void _ShowCurrencyCalculatorScreen()
    {
       // cout << "\nCurrency Calculator Screen Will be here...\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrenciesMainMenueOption(enCurrenciesMainMenueOptions CurrencyExchangeOption)
    {
        switch (CurrencyExchangeOption)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenue();
        }

        case enCurrenciesMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenue();
        }

        case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenue();
        }

        case enCurrenciesMainMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenue();
        }

        case enCurrenciesMainMenueOptions::eMainMenue:
        {

        }

        }
    }

public:

	static void ShowCurrenciesMenue()
	{
        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrenciesMainMenueOption(enCurrenciesMainMenueOptions(_ReadCurrenciesMainMenueOption()));

	}

};

