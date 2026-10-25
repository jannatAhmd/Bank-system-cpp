#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<iomanip>

class clsCurrenciesListScreen:protected clsScreen
{
private:
    static void _PrintCurrencyRecordLine(clsCurrency &Currency)
    {
        cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
    }

public:
	static void ShowCurrenciesListScreen()

    {


        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency(ies).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << setw(8) << left << "Code";
        cout << "| " << setw(45) << left << "Name";
        cout << "| " << setw(10) << left << "Rate/(1$)";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency& Currency : vCurrencies)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

