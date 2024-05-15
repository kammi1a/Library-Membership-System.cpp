#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct LibraryMember {
    string name;
    string address;
    string contact;
    LibraryMember(const string& n, const string& addr, const string& cont): name(n), address(addr), contact(cont) {}
};


void registerMember(vector<LibraryMember>& members, const string& name, const string& address, const string& contact) {
    LibraryMember newMember(name, address, contact);
    members.push_back(newMember);
    cout << "Member " << name << " registered successfully!\n";
}


void renewMembership(vector<LibraryMember>& members, const string& name) {
    for (auto& member : members) {
        if (member.name == name) {
            cout << "Membership renewed for " << name << endl;
            return;
        }
    }
    cout << "Member not found!\n";
}


void cancelMembership(vector<LibraryMember>& members, const string& name) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->name == name) {
            members.erase(it);
            cout << "Membership canceled for " << name << endl;
            return;
        }
    }
    cout << "Member not found!\n";
}


int main() {
    vector<LibraryMember> members;
    int choice;
    do {
        cout << "Choose an option:\n";
        cout << "1. Register member\n";
        cout << "2. Renew membership\n";
        cout << "3. Cancel membership\n";
        cout << "4. Display all members\n";
        cout << "5. Exit\n";
        cin >> choice;
        cin.ignore(); 

        string name, address, contact;
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter contact: ";
                getline(cin, contact);
                registerMember(members, name, address, contact);
                break;
            case 2:
                cout << "Enter name to renew membership: ";
                getline(cin, name);
                renewMembership(members, name);
                break;
            case 3:
                cout << "Enter name to cancel membership: ";
                getline(cin, name);
                cancelMembership(members, name);
                break;
            case 4:
                cout << "All Members:\n";
                for (const auto& member : members) {
                    cout << "Name: " << member.name << ", Address: " << member.address << ", Contact: " << member.contact << endl;
                }
                break;
        }
    } while (choice != 5);
    return 0;
}
