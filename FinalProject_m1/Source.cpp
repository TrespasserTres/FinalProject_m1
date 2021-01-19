#include "Header.h"
#include <string>


void User::setLogin(string log)                 // Присваивание логина
{
    Login = log;
}

void User::setPassword(string pas)              // Присваивание пароля
{
    Password = pas;
}

void User::setName(string nam)              // Присваивание имени
{
    Name = nam;
}

void User::displayUser()                        // Вывод логина, имени и пароля
{
    cout << "Login - " << Login << endl;
    cout << "Password - " << Password << endl;
    cout << "Name - " << Name << endl;
}

string User::getLogin()                        // Выдача имени
{
    return Login;
}

string User::getPassword()                     // Выдача пароля
{
    return Password;
}

string User::getName()                        // Выдача Имени
{
    return Name;
}

void User::getmessage(short a, short b)        // Отображение сообщений
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

void User::resize(short a)                          // Сдвиг сообщений (при достижении лимита в архивировании)
{
    for (short i = 0; i < 9; i++)
    {
        User::mail[a][i] = User::mail[a][i + 1];
    }
}

int backint(string a)                        // Перевод текста в int (отсекаем неправильный выбор в меню)
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