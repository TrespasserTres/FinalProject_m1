#include "Header.h"
#include <string>


void User::setLogin(string log)                 // ������������ ������
{
    Login = log;
}

void User::setPassword(string pas)              // ������������ ������
{
    Password = pas;
}

void User::setName(string nam)              // ������������ �����
{
    Name = nam;
}

void User::displayUser()                        // ����� ������, ����� � ������
{
    cout << "Login - " << Login << endl;
    cout << "Password - " << Password << endl;
    cout << "Name - " << Name << endl;
}

string User::getLogin()                        // ������ �����
{
    return Login;
}

string User::getPassword()                     // ������ ������
{
    return Password;
}

string User::getName()                        // ������ �����
{
    return Name;
}

void User::getmessage(short a, short b)        // ����������� ���������
{
    if (b == 0)
    {
        cout << "No message from this user" << endl;
    }
    else if (b > 0)
    {
        for (short i = 0; i < b; i++)
        {
            cout << User::mail[a][i] << endl;
        }
    }
    cout << endl;
}

void User::resize(short a)                          // ����� ��������� (��� ���������� ������ � �������������)
{
    for (short i = 0; i < 9; i++)
    {
        User::mail[a][i] = User::mail[a][i + 1];
    }
}

int backint(string a)                        // ������� ������ � int (�������� ������������ ����� � ����)
{
    int b;
    if (a == "1")
    {
        b = 1;
    }
    else if (a == "2")
    {
        b = 2;
    }
    else if (a == "3")
    {
        b = 3;
    }
    else if (a == "4")
    {
        b = 4;
    }
    else b = 11;
    return b;
}