#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Defining a struct to represent a library member with name, address, and contact details.
struct LibraryMember {
    string name; 
    string address; 
    string contact;
};

vector<LibraryMember> members; // Declaring a vector to store library members globally.

void registerMember(string name, string address, string contact) {
    LibraryMember newMember = {name, address, contact};
    members.push_back(newMember);
    cout << "Member " << name << " registered successfully!\n";
}

void renewMembership(string contact) {
    bool found = false; // Flag indicating whether member is found or not.
    for (auto& member : members) {
        if (member.contact == contact) {
            cout << "Membership renewed for " << member.name << endl;
            found = true;
            break;
        }
    }
    if (!found) { 
        cout << "Member not found!\n";
    }
}

void cancelMembership(string contact) {
    bool found = false; // Flag indicating whether member is found or not.
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->contact == contact) {
            members.erase(it);
            cout << "Membership canceled for " << it->name << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Member not found!\n"; 
    }
}

void displayAllMembers() {
    cout << "All Members:\n";
    for (const auto& member : members) {
        cout << "Name: " << member.name << ", Address: " << member.address << ", Contact: " << member.contact << endl;
    }
}

void saveHistoryToFile() {
    ofstream file("data.txt");
    if (file.is_open()) {
        for (const auto& member : members) {
            file << "Name: " << member.name << ", Address: " << member.address << ", Contact: " << member.contact << endl;
        }
        cout << "History saved to data.txt" << endl;
    } else {
        cerr << "Unable to open file: data.txt" << endl;
    }
}

int main() {
    int choice; // Variable to store user's choice.
    do {
        cout << "Choose an option:\n";
        cout << "1. Register member\n";
        cout << "2. Renew membership\n";
        cout << "3. Cancel membership\n";
        cout << "4. Display all members\n";
        cout << "5. Save history to file\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Read user's choice.

        string name, address, contact; // Variables for member details.
        switch (choice) {
            case 1: // Опция для регистрации нового члена.
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter address: ";
                getline(cin >> ws, address); // Считываем адрес с учётом пробелов.
                cout << "Enter contact: ";
                cin >> contact; // Считываем контакт.
                registerMember(name, address, contact); // Вызываем функцию регистрации.
                break;
            case 2: // Option to renew membership.
                cout << "Enter contact to renew membership: ";
                cin >> contact;
                renewMembership(contact); // Call renewMembership function.
                break;
            case 3: // Option to cancel membership.
                cout << "Enter contact to cancel membership: ";
                cin >> contact;
                cancelMembership(contact); // Call cancelMembership function.
                break;
            case 4: // Option to display all members.
                displayAllMembers(); // Call displayAllMembers function.
                break;
            case 5: // Option to save members to file.
                saveHistoryToFile(); // Call saveHistoryToFile function.
                break;
        }
    } while (choice != 6); // Loop until user chooses to exit.
    return 0; // Return 0 to indicate successful completion of program.
}
