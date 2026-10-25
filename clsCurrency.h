#pragma once
#include<iostream>
#include"clsString.h"
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h"

using namespace std;

class clsCurrency
{
private:
	enum enMode{EmptyMode=1,UpdateMode=2};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line,string Seperator= "#//#")
	{
		vector <string> vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
			stof(vCurrencyData[3]));
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		vector <clsCurrency> vCurrencies;

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrencies;
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency,string Separator="#//#")
	{
		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Separator;
		stCurrencyRecord += Currency.CurrencyCode() + Separator;
		stCurrencyRecord += Currency.CurrencyName() + Separator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;

			for (clsCurrency& Currency : vCurrencies)
			{
				DataLine = _ConvertCurrencyObjectToLine(Currency);
				MyFile << DataLine<<endl;
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& Currency : vCurrencies)
		{
			if (Currency.CurrencyCode() == CurrencyCode())
			{
				Currency = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(vCurrencies);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}

	string Country() 
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);

		return (!Currency.IsEmpty());
	}

	static vector < clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	 float ConvertFromUSD(float Amount)
	{
		return Amount * Rate() ;
	}

	 float ConvertToUSD(float Amount)
	{
		return Amount / Rate();
	}

	 float ConvertToAnotherCurrency(float Amount,clsCurrency Currency2)
	 {
		 float AmountInUSD = ConvertToUSD(Amount);

		 if (Currency2.CurrencyCode() == "USD")
		 {
			 return AmountInUSD;
		 }

		 return AmountInUSD * Currency2.Rate();
	 }

};

