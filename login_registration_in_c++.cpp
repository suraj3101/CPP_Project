#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{

    int choice;
    cout << "\t\t\t__________________________________________\n\n\n";
    cout << "\t\t\t         Welcome To The Login Page________\n\n\n";
    cout << "\t\t\t__________         Menu          __________\n\n\n";
    cout << "                                                   \n\n";
    cout << "\t| Press 1 to LOGIN                        |" << endl;
    cout << "\t| Press 2 to REGISTER                     |" << endl;
    cout << "\t| Press 3 to If you forgot your PASSWORD  |" << endl;
    cout << "\t| Press 4 to EXIT                         |" << endl;
    cout << "\n\t\t\t Please Enter your Choice: ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\t\t\t Thank You! \n\n";

    default:
        system("cls");
        cout << "\t\t\t Select Valid Choice \n"
             << endl;
        main();
    }
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please Enter the username and password : " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userId;
    cout << "\t\t\t PASSWORD ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }

    input.close();

    if (count == 1)
    {
        cout << userId << "\n Your LOGIN is successful \n Thanks for logging in! \n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your usename and password\n";
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration is Successful! \n";
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No Worries \n";
    cout << "Press 1 to serach your id by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter Your Choice :";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\t\t\t Enter the username which you remembered :";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is found! \n";
            cout << "\n\n Your password is : " << spass;
            main();
        }
        else
        {
            cout << "\n\t Sorry! Your account is not found! \n";
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }

    default:
        cout<<"\t\t\t Wrong choice! Please Try again"<<endl;
        forgot();
    }
}