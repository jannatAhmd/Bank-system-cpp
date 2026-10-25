#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

class clsTransferLogScreen:protected clsScreen
{
private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {
       
        cout << setw(8) << left << "" << "| " << left << setw(23) << TransferLogRecord.DateTime;
        cout << "| " << left << setw(8) << TransferLogRecord.SourceAccountNumber;
        cout << "| " << left << setw(8) << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << left << setw(8) << TransferLogRecord.Amount;
        cout << "| " << left << setw(10) << TransferLogRecord.SrcBalanceAfter;
        cout << "| " << left << setw(10) << TransferLogRecord.DesBalanceAfter;
        cout << "| " << left << setw(8) << TransferLogRecord.UserName;
        
    }
public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecords = clsBankClient::GetTransferLogList();
		string Title = "\t Transfer Log List Screen.";
		string SubTitle= "\t    (" + to_string(vTransferLogRecords.size()) + ") Records(s).";

		_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vTransferLogRecords.size() == 0)
            cout << "\t\t\t\tNo Transfer Logs Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord& Record : vTransferLogRecords)
            {

                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
	
};

