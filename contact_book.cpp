#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to add a new contact
void addContact(map<string, string> &contacts)
{
    string name, phoneNumber;
    cout << "Enter name: ";
    getline(cin >> ws, name); // Use getline to handle spaces in names
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    contacts[name] = phoneNumber;
    cout << "Contact added successfully." << endl;
}

// Function to display all contacts
void displayContacts(const map<string, string> &contacts)
{
    cout << "Contacts:" << endl;
    for (const auto &contact : contacts)
    {
        cout << "Name: " << contact.first << ", Phone Number: " << contact.second << endl;
    }
}

// Function to search for a contact
void searchContact(const map<string, string> &contacts)
{
    string name;
    cout << "Enter name to search: ";
    getline(cin >> ws, name); // Use getline to handle spaces in names
    auto it = contacts.find(name);
    if (it != contacts.end())
    {
        cout << "Name: " << it->first << ", Phone Number: " << it->second << endl;
    }
    else
    {
        cout << "Contact not found." << endl;
    }
}

int main()
{
    map<string, string> contacts;
    int choice;

    do
    {
        cout << "\nContact Book App" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Clear input buffer

        switch (choice)
        {
        case 1:
            addContact(contacts);
            break;
        case 2:
            displayContacts(contacts);
            break;
        case 3:
            searchContact(contacts);
            break;
        case 4:
            cout << "Exiting program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
