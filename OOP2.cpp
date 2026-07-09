
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void Find(string AccountNumber)
{
    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();
}

void Find(string AccountNumber , string PinCode)
{
    clsBankClient Client1 = clsBankClient::Find(AccountNumber,PinCode);
    Client1.Print();
}

void ReadClientInfo(clsBankClient& Client)
{
    cout << "Enter First Name: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "Enter Last Name: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "Enter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "Enter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "Enter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "Enter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();

}

void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nEnter Client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nThis Client isn't Exist! , Enter other Client Number : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);

    cout << "\n\nUpdate Client Info: ";
    cout << "\n-------------------\n";

    ReadClientInfo(Client);
    Client._Update();

}


int main()
{
    //UpdateClient();

    
    Find("A101");




    system("pause>0");
}
