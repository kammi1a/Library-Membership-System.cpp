#include <bits.stdc++.h>

// Defining a struct to represent a library member with name, address, and contact details.
struct LibraryMember {
    string name;
    string address;
    string contact;
};

// Declaring a vector to store library members globally.
vector<LibraryMember> members;

// Function to register a new library member.
void registerMember(const string& name, const string& address, const string& contact) {
    members.push_back({name, address, contact});
    cout << "Member " << name << " registered successfully!\n";
}

// Function to renew the membership of a library member.
void renewMembership(const string& name) {
    // Finding the member with the specified name.
    auto it = find_if(members.begin(), members.end(), [&name](const LibraryMember& m) { return m.name == name; });
    // Checking if member exists.
    if (it != members.end()) {
        cout << "Membership renewed for " << name << endl;
    } else {
        cout << "Member not found!\n";
    }
}

// Function to cancel the membership of a library member.
void cancelMembership(const string& name) {
    auto it = find_if(members.begin(), members.end(), [&name](const LibraryMember& m) { return m.name == name; });
    if (it != members.end()) {
        // Removing the member from the vector.
        members.erase(it);
        cout << "Membership canceled for " << name << endl;
    } else {
        // Printing a message if member not found.
        cout << "Member not found!\n";
    }
}

void displayAllMembers() {
    cout << "All Members:\n";
    // Looping through all members and printing their details.
    for (const auto& member : members) {
        cout << "Name: " << member.name << ", Address: " << member.address << ", Contact: " << member.contact << endl;
    }
}

int main() {
    int choice;
    do {
        // Printing menu for user choice.
        cout << "Choose an option:\n";
        cout << "1. Register member\n";
        cout << "2. Renew membership\n";
        cout << "3. Cancel membership\n";
        cout << "4. Display all members\n";
        cout << "5. Exit\n";
        // Reading user's choice.
        cin >> choice;
        cin.ignore();  // Clearing input buffer.
        
        string name, address, contact;
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter contact: ";
                getline(cin, contact);
                registerMember(name, address, contact);
                break;
            case 2:
                cout << "Enter name to renew membership: ";
                getline(cin, name);
                renewMembership(name);
                break;
            case 3:
                cout << "Enter name to cancel membership: ";
                getline(cin, name);
                cancelMembership(name);
                break;
            case 4:
                displayAllMembers();
                break;
        }
    } while (choice != 5); // Loop until user chooses to exit.
    return 0;
}
