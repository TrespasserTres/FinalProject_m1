#include<iostream>
#include <string>
#include "Header.h"
using namespace std;
#pragma runtime_checks( "", off )
#pragma warning( push )
#pragma warning( disable : 4700 )

int main()
{
    User* First = new User();  // Создание пользователя 1
    User* Second = new User(); // Создание пользователя 2
    User* Third = new User();  // Создание пользователя 3
    string logcr;              // Переменная для создания Логина
    string namecr;             // Переменная для создания Имени
    string b;                  // Переменная для создания Пароля
    string c;                  // Переменная для меню temp
    int choice;                // Переменная для меню
    short d = 0;               // счетчик пользователей
    string logent;             // Переменная ввод Логина
    string f;                  // Переменная ввод Пароля
    bool y = true;             // Переменная выхода из программы
    bool x = true;             // Переменная выхода из чата
    string mes;                // Сообщения
    short count12 = 0;               // Счетчик сообщений для пользователя 1
    short count13 = 0;               // Счетчик сообщений для пользователя 1
    short count21 = 0;               // Счетчик сообщений для пользователя 2
    short count23 = 0;               // Счетчик сообщений для пользователя 2
    short count31 = 0;               // Счетчик сообщений для пользователя 3
    short count32 = 0;               // Счетчик сообщений для пользователя 3
    while (y == true)
    {
        cout << "1 - Create user / 2 - Enter chat / 3 - Exit program / 4 - HELP" << endl;
        cin >> c;
        choice = backint(c);
        switch (choice)
        {
        case 1:                                                            //Регистрация пользователей
            if (d == 0)
            {
                cout << "Enter login: " << endl;                           //Запрос логина для первого пользователя
                cin >> logcr;
                cout << "Enter Password: " << endl;                        //Запрос пароля для первого пользователя
                cin >> b;
                cout << "Enter Name: " << endl;                            //Запрос имени для первого пользователя
                cin >> namecr;
                First->setLogin(logcr);
                First->setPassword(b);
                First->setName(namecr);
                d++;
            }
            else if (d == 1)
            {
                cout << "Enter login: " << endl;                           //Запрос логина для второго пользователя
                cin >> logcr;
                if (logcr == First->getLogin())                            //Проверка свободного логина
                {
                    cout << "This login is buisy " << endl;
                }
                else
                {
                    cout << "Enter Password: " << endl;                    //Запрос пароля для второго пользователя
                    cin >> b;
                    cout << "Enter Name: " << endl;                    //Запрос пароля для второго пользователя
                    cin >> namecr;
                    Second->setLogin(logcr);
                    Second->setPassword(b);
                    Second->setName(namecr);
                    d++;
                }
            }
            else if (d == 2)
            {
                cout << "Enter login: " << endl;                           //Запрос логина для третьего пользователя
                cin >> logcr;
                if ((logcr == First->getLogin()) || (logcr == Second->getLogin())) //Проверка свободного логина
                {
                    cout << "Login is buisy " << endl;
                }
                else
                {
                    cout << "Enter Password: " << endl;                    //Запрос пароля для третьего пользователя
                    cin >> b;
                    cout << "Enter Name: " << endl;                        //Запрос пароля для второго пользователя
                    cin >> namecr;
                    Third->setLogin(logcr);
                    Third->setPassword(b);
                    Third->setName(namecr);
                    d++;
                }
            }
            else cout << "Too many users" << endl;
            break;
        case 2:                                                            //Вход в Чат
            cout << "Enter login: " << endl;                               //Ввод логина
            cin >> logent;
            cout << "Enter password: " << endl;                            //Ввод пароля
            cin >> f;
            if (((logent == First->getLogin()) && (f == First->getPassword())) ||      //Проверка логина и пароля
                ((logent == Second->getLogin()) && (f == Second->getPassword())) ||
                ((logent == Third->getLogin()) && (f == Third->getPassword())))
            {
                cout << "Welcome to chat" << endl;
                bool x = true;
                while (x == true)
                {
                    cout << "1 - Check messages / 2 - Write a message / 3 Exit chat " << endl;
                    cin >> c;
                    choice = backint(c);
                    switch (choice)
                    {
                    case 1:
                        if (logent == First->getLogin() && (d == 2))       //Проверка сообщений от пользователя 2
                        {
                            cout << "Your message from " << Second->getName() << endl;
                            First->getmessage(1, count21);
                        }
                        else if (logent == First->getLogin() && (d == 3))       //Проверка сообщений от пользователя 2 и 3
                        {
                            cout << "Your message from " << Second->getName() << endl;
                            First->getmessage(1, count21);
                            cout << "Your message from " << Third->getName() << endl;
                            First->getmessage(2, count31);
                        }
                        else if (logent == Second->getLogin() && (d == 2))       //Проверка сообщений от пользователя 1
                        {
                            cout << "Your message from " << First->getName() << endl;
                            Second->getmessage(0, count12);
                        }
                        else if (logent == Second->getLogin() && (d == 3))       //Проверка сообщений от пользователя 1 и 3
                        {
                            cout << "Your message from " << First->getName() << endl;
                            Second->getmessage(0, count12);
                            cout << "Your message from " << Third->getName() << endl;
                            Second->getmessage(2, count32);
                        }
                        else if (logent == Third->getLogin())       //Проверка сообщений от пользователя 1 и 2
                        {
                            cout << "Your message from " << First->getName() << endl;
                            Third->getmessage(0, count13);
                            cout << "Your message from " << Second->getName() << endl;
                            Third->getmessage(1, count23);
                        }
                        break;
                    case 2:
                        if (d == 1)                                         //Отправка сообщений 1 пользователь в чате
                        {
                            cout << "No mo Users in chat" << endl;
                        }
                        else if (d == 2)                                    //Отправка сообщений 2 пользователя в чате
                        {
                            if (logent == First->getLogin())
                            {
                                cout << "send message user name " << Second->getName() << endl;  //Отправка от 1го 2му
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                getline(cin, mes);
                                if (count12 < 9)
                                {
                                    Second->mail[0][count12] = mes;
                                    count12++;
                                }
                                else
                                {
                                    Second->mail[0][count12] = mes;
                                    Second->resize(0);
                                }
                            }
                            else if (logent == Second->getLogin())                               //Отправка от 2го 1му
                            {
                                cout << "send message user name " << First->getName() << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                getline(cin, mes);
                                if (count21 < 9)
                                {
                                    First->mail[1][count21] = mes;
                                    count21++;
                                }
                                else
                                {
                                    First->mail[1][count21] = mes;
                                    First->resize(1);
                                }
                            }
                        }
                        else if (d == 3)                                    //Отправка сообщений 3 пользователя в чате
                        {
                            if (logent == First->getLogin())
                            {
                                cout << "1 - " << Second->getName() << "  2 - " << Third->getName() << endl; //выбор пользователя для отправки
                                cin >> c;
                                choice = backint(c);
                                if (choice == 1)
                                {
                                    cout << "send message user name " << Second->getName() << endl;  //Отправка от 1го 2му
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    getline(cin, mes);
                                    if (count12 < 9)
                                    {
                                        Second->mail[0][count12] = mes;
                                        count12++;
                                    }
                                    else
                                    {
                                        Second->mail[0][count12] = mes;
                                        Second->resize(0);
                                    }
                                }
                                else if (choice == 2)
                                {
                                    cout << "send message user name " << Third->getName() << endl;   //Отправка от 1го 3му
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    getline(cin, mes);
                                    if (count13 < 9)
                                    {
                                        Third->mail[0][count13] = mes;
                                        count13++;
                                    }
                                    else
                                    {
                                        Third->mail[0][count13] = mes;
                                        Third->resize(0);
                                    }
                                }
                            }
                            else if (logent == Second->getLogin())
                            {
                                cout << "1 - " << First->getName() << "  2 - " << Third->getName() << endl; //выбор пользователя для отправки
                                cin >> c;
                                choice = backint(c);
                                if (choice == 1)
                                {
                                    cout << "send message user name " << First->getName() << endl;  //Отправка от 2го 1му
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    getline(cin, mes);
                                    if (count21 < 9)
                                    {
                                        First->mail[1][count21] = mes;
                                        count21++;
                                    }
                                    else
                                    {
                                        First->mail[1][count21] = mes;
                                        First->resize(1);
                                    }
                                }
                                else if (choice == 2)
                                {
                                    cout << "send message user name " << Third->getName() << endl;  //Отправка от 2го 3му
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    getline(cin, mes);
                                    if (count23 < 9)
                                    {
                                        Third->mail[1][count23] = mes;
                                        count23++;
                                    }
                                    else
                                    {
                                        Third->mail[1][count23] = mes;
                                        Third->resize(1);
                                    }
                                }
                            }
                            else if (logent == Third->getLogin())
                            {
                                cout << "1 - " << First->getName() << "  2 - " << Second->getName() << endl; //выбор пользователя для отправки
                                cin >> c;
                                choice = backint(c);
                                if (choice == 1)
                                {
                                    cout << "send message user name " << First->getName() << endl;  //Отправка от 3го 1му
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    getline(cin, mes);
                                    if (count31 < 9)
                                    {
                                        First->mail[2][count31] = mes;
                                        count31++;
                                    }
                                    else
                                    {
                                        First->mail[2][count31] = mes;
                                        First->resize(2);
                                    }
                                }
                                else if (choice == 2)
                                {
                                    cout << "send message user name " << Second->getName() << endl; //Отправка от 3го 2му
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    getline(cin, mes);
                                    if (count32 < 9)
                                    {
                                        Second->mail[2][count32] = mes;
                                        count32++;
                                    }
                                    else
                                    {
                                        Second->mail[2][count32] = mes;
                                        Second->resize(2);
                                    }
                                }
                            }
                        }
                        break;
                    case 3:                                                //Выход из Чата
                        x = false;
                        break;
                    default:
                        cout << "Bad choise" << endl;
                        break;
                    }
                }
            }
            else cout << "Wrong Login or Password " << endl;
            break;
        case 3:
            y = false;
            break;
        case 4:                                                            //Подсмотреть логин/пароль
            if (d > 0)
            {
                First->displayUser();
            }
            if (d > 1)
            {
                Second->displayUser();
            }
            if (d > 2)
            {
                Third->displayUser();
            }
            break;
        default:
            cout << "Bad choise" << endl;
            break;
        }
        cout << endl;
    }
    delete First;
    delete Second;
    delete Third;
    return 0;
}