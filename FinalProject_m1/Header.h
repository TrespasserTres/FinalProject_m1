#pragma once
#include <iostream>
#include <string>
using namespace std;

class User                  // Класс пользователь с архивом сообщений, паролем и именем
{
public:
    string mail[3][10]{};
    void resize(short a);
    void setLogin(string log);
    void setPassword(string pas);
    void setName(string nam);
    void displayUser();
    string getLogin();
    string getPassword();
    string getName();
    void getmessage(short a, short b);
private:
    string Login;
    string Password;
    string Name;
};

int backint(string a);   // Перевод текста в int (отсекаем неправильный выбор в меню)