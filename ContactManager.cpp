#include "ContactManager.hpp"
#include <fstream>
using namespace std;

// Default Constructor
ContactManager::ContactManager()

{
    cout << "++++++++++++++++++++++++++++++++" << endl;
    cout << "Welcome to the Contact Manager" << endl;
    cout << "Author:Dhanraj Chitte" << endl;
    cout << "Version:1.01 " << endl;
    cout << "Released Date:22 Feburary 2024" << endl;
    cout << "Guide By:Dr.Abdullah Ansari Sir" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++" << endl;
}

// Parameterised Constructor
void ContactManager::add(ulong Number, string Name, string Email, string Title)
{
    info temp;
    temp.number = Number;
    temp.name = Name;
    temp.email = Email;
    temp.title = Title;

    data.push_back(temp);
}

// List the Contacts
void ContactManager::list()
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << (i + 1) << " " << data[i].title << " Name:" << data[i].name << " PhoneNo.:" << data[i].number << " EmailID:" << data[i].email << endl;
    }
}

// Add the Contact from the User
void ContactManager::add()
{
    string T;
    cout << "Enter the title of the user" << endl;
    getline(cin, T);

    string N;
    cout << "Enter the name of the user" << endl;
    getline(cin, N);

    ulong Nu;
    cout << "Enter the PhoneNo. of the user" << endl;
    cin >> Nu;
    cin.ignore(); // To consume the newline character left in the buffer

    string E;
    // cin.ignore(); // To consume the newline character left in the buffer
    cout << "Enter the email of the user" << endl;
    getline(cin, E);

    info temp1;
    temp1.title = T;
    temp1.name = N;
    temp1.number = Nu;
    temp1.email = E;
    data.push_back(temp1);
}

// Edit the Contact
void ContactManager::edit()
{

    // ask user to select which user to be edited
    int id;
    cout << "Select the User ID to Edit" << endl;
    cin >> id;
    cin.ignore();

    cout << "Enter the New Title" << endl;
    getline(cin, data[id - 1].title);
    // cin >> data[id - 1].title;

    cout << "Enter the New Name" << endl;
    getline(cin, data[id - 1].name);
    // cin >> data[id - 1].name;

    cout << "Enter the New PhoneNo" << endl;
    cin >> data[id - 1].number;
    cin.ignore();

    cout << "Enter the New EmailID" << endl;
    // cin >> data[id - 1].email;
    getline(cin, data[id - 1].email);
}

// Edit PhoneNumber only
void ContactManager::editPhoneNumber()
{
    int id;
    cout << "Select the User ID to Edit Phone Number" << endl;
    cin >> id;
    cin.ignore();

    cout << "Enter the New PhoneNo" << endl;
    cin >> data[id - 1].number;
    cin.ignore();
}

// Edit Name Only
void ContactManager::editName()
{
    int id;
    cout << "Select the User ID to Edit Name " << endl;
    cin >> id;
    cin.ignore();

    cout << "Enter the New Name" << endl;
    getline(cin, data[id - 1].name);
}

// Edit Email Only
void ContactManager::editEmail()
{
    int id;
    cout << "Select the User ID to Edit EmailID " << endl;
    cin >> id;
    cin.ignore();

    cout << "Enter the New EmailID" << endl;
    getline(cin, data[id - 1].email);
}

// Edit Title
void ContactManager::editTitle()
{
    int id;
    cout << "Select the User ID to Edit Title " << endl;
    cin >> id;
    cin.ignore();

    cout << "Enter the New Title" << endl;
    getline(cin, data[id - 1].title);
}

// Delete the User all data
void ContactManager::removeUser()
{
    // ask user to select which user to be deleted
    int id;
    cout << "Select the User ID to Delete" << endl;
    cin >> id;
    cin.ignore();

    /*data[id - 1].name = "";
    data[id - 1].email = "";
    data[id - 1].title = "";
    data[id - 1].number = 0;*/
    data.erase(data.begin() + id - 1);
}

// Remove User name only
void ContactManager::removeUserName()
{
    // ask user to select which user to be deleted
    int id;
    cout << "Select the User ID to Delete his name" << endl;
    cin >> id;
    cin.ignore();
    data[id - 1].name = "";
}

// Remove Phone number only
void ContactManager::removeUserNumber()
{
    // ask user to select which user to be deleted
    int id;
    cout << "Select the User ID to Delete his Number" << endl;
    cin >> id;
    cin.ignore();

    data[id - 1].number = 0;
}

// Remove Email only
void ContactManager::removeUserEmail()
{
    // ask user to select which user to be deleted
    int id;
    cout << "Select the User ID to Delete his EmailID" << endl;
    cin >> id;
    cin.ignore();

    data[id - 1].email = "";
}

// Search User Name
void ContactManager::searchName()
{
    // ask user to select which user to be search
    int id;
    cout << "Select the User ID to search his Name" << endl;
    cin >> id;
    cin.ignore();

    cout << "Name:" << data[id - 1].name << endl;
}

// Search User Phone Number
void ContactManager::searchNumber()
{
    // ask user to select which user to be search
    int id;
    cout << "Select the User ID to search his Number" << endl;
    cin >> id;
    cin.ignore();

    cout << "Number:" << data[id - 1].number << endl;
}

// Search User Email
void ContactManager::searchEmail()
{
    // ask user to select which user to be search
    int id;
    cout << "Select the User ID to search his Email" << endl;
    cin >> id;
    cin.ignore();

    cout << "Email:" << data[id - 1].email << endl;
}

// Take a backup all contacts in the backUp.txt file
void ContactManager::backUp()
{
    ofstream outputFile("backUp.txt");

    if (outputFile.is_open())
    {
        for (size_t i = 0; i < data.size(); i++)
        {
            outputFile << "Title: " << data[i].title << endl;
            outputFile << "Email: " << data[i].email << endl;
            outputFile << "Number: " << data[i].number << endl;
            outputFile << "Name: " << data[i].name << endl;
        }

        outputFile.close();
        cout << "Backup successfully saved to backup.txt" << endl;
    }
    else
    {
        cout << "Unable to open the file" << endl;
    }
}
