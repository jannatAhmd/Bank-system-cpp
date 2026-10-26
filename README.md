
## Features
The system has 26 screens in these modules:
- **Login:** username and password screen at startup
- **Clients:** show list, add, delete, update, find
- **Transactions:** deposit, withdraw, total balances, transfer, transfer log
- **Manage users:** list, add, delete, update, find
- **Login register:** a list of all user logins (date/time, username, password, permissions)
- **Currency exchange:** list currencies, find currency, update rate, currency calculator

## System rules
- **Permissions:** each user can only open the screens they are allowed to use
- **Login attempts:** 3 attempts, then the program exits
- **Log out:** returns the user to the login screen

## Tech stack
C++, OOP, Visual Studio, file storage (.txt files)

## Sample data
The project includes sample .txt files: Clients.txt, Users.txt, TransferLog.txt, LoginRegister.txt, Currencies.txt.

Sample login: username `User2`, password `1234` (sample account only, with fake data).

## How to run
1. Open MyLibs.vcxproj file in Visual Studio.
2. Make sure the .txt files are in the same folder as the program.
3. Press F5.

## What I learned
Structuring code so it is easy to extend without breaking existing code, and moving from functions to OOP classes.