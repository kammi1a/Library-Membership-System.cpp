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

vector<LibraryMember> members; // Объявляем вектор для хранения членов библиотеки глобально.

void registerMember(string name, string address, string contact) {
    members.push_back({name, address, contact}); // Добавляем нового члена в вектор.
    cout << "Member " << name << " registered successfully!\n";
}

void renewMembership(string name) {
    bool found = false; // Флаг, показывающий, был ли найден член библиотеки.
    for (auto& member : members) { // Проходим по всем членам библиотеки.
        if (member.name == name) { // Если имя члена соответствует заданному имени.
            cout << "Membership renewed for " << name << endl;
            found = true; // Устанавливаем флаг, что член найден.
            break; // Выходим из цикла, так как член найден.
        }
    }
    if (!found) { 
        cout << "Member not found!\n";
    }
}

void cancelMembership(string name) {
    bool found = false; // Флаг, показывающий, был ли найден член библиотеки.
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->name == name) { // Если имя члена соответствует заданному имени.
            members.erase(it); // Удаляем члена из вектора.
            cout << "Membership canceled for " << name << endl;
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

void saveHistoryToFile(string filename) {
    ofstream file(filename); // Открываем файл для записи.
    if (file.is_open()) { 
        for (const auto& member : members) { 
            file << "Name: " << member.name << ", Address: " << member.address << ", Contact: " << member.contact << endl; // Записываем данные в файл.
        }
        cout << "History saved to " << filename << endl; // Выводим сообщение об успешном сохранении.
    } 
}

int main() {
    int choice; // Переменная для хранения выбора пользователя.
    do {
        cout << "Choose an option:\n";
        cout << "1. Register member\n";
        cout << "2. Renew membership\n";
        cout << "3. Cancel membership\n";
        cout << "4. Display all members\n";
        cout << "5. Save history to file\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Считываем выбор пользователя.

        string name, address, contact; // Переменные для хранения данных члена библиотеки.
        switch (choice) {
            case 1: // Опция для регистрации нового члена.
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter address: ";
                cin >> address; 
                cout << "Enter contact: ";
                cin >> contact; 
                registerMember(name, address, contact); // Вызываем функцию регистрации.
                break;
            case 2: // Опция для продления членства.
                cout << "Enter name to renew membership: ";
                cin >> name;
                renewMembership(name);
            case 3: // Опция для отмены членства.
                cout << "Enter name to cancel membership: ";
                cin >> name;
                cancelMembership(name); 
                break;
            case 4: // Опция для отображения всех членов.
                displayAllMembers(); 
                break;
            case 5: // Опция для сохранения истории в файл.
                {
                    string filename;
                    cout << "Enter filename to save history: ";
                    cin >> filename;
                    saveHistoryToFile(filename); // Вызываем функцию сохранения истории.
                }
                break;
        }
    } while (choice != 6); // Повторяем цикл, пока пользователь не выберет выход.
    return 0; 
}
