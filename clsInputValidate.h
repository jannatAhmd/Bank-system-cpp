//ProgrammingAdivces.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

template<class Type>
class clsInputValidate
{

public:

	static  bool  IsNumberBetween(Type Number, Type From, Type To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	static Type ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		Type Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static Type ReadNumberBetween(Type From, Type To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		Type Number = ReadNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber();
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static Type ReadString()
	{
		Type  S1;
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

	static Type ReadPositiveNumber(string ErrorMessage="\nInvalid Number,Please Enter Positive Number: ")
	{
		Type Number=0;
		Number=ReadNumber();

		while (Number <= 0) 
		{
			cout << ErrorMessage;
			Number = ReadNumber();
		}

		return Number;
	}


};


