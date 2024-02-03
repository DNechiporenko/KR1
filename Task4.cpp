#include <iostream>
#include <string>

using namespace std;

const int MAX_CONTACTS = 100;

struct Contact {
    string name;
    string phone;
};

Contact contacts[MAX_CONTACTS]; //Объявляем массив, состоящий из структур 
int ContactsNow = 0;

void addContact() {
    if (ContactsNow >= MAX_CONTACTS) {
        cout << "Вы не можете добавить еще контакт, хранилище заполнено";
        return;
    }

    Contact newContact;
    std::cout << "Введите имя контакта: ";
    getline(cin, newContact.name);
    std::cout << "Введите номер телефона: ";
    getline(cin, newContact.phone);
    contacts[ContactsNow++] = newContact;
    std::cout << "Контакт добавлен" << endl;
}

void deleteContact() {
    string name;
    cout << "Введите имя для удаления: ";
    getline(cin, name);

    for (int i = 0; i < ContactsNow; i++) {
        if (contacts[i].name == name) {
            for (int j = i; j < ContactsNow - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            ContactsNow--;
            cout << "Контакт удален" << endl;
            return;
        }
    }
}

void updateContact() {
    string name;
    cout << "Введите имя контакта для изменения: ";
    getline(cin, name);

    for (int i = 0; i < ContactsNow; i++) {
        if (contacts[i].name == name) {
            cout << "Введите номер телефона: ";
            getline(cin, contacts[i].phone);
            cout << "Контакт обновлен" << endl;
            return;
        }
    }
}

void showContacts() {
    for (int i = 0; i < ContactsNow; i++) {
        cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    while (true) {
        cout << "\nТелефонный справочник\n";
        cout << "1. Добавить контакт\n";
        cout << "2. Удалить контакт\n";
        cout << "3. Обновить контакт\n";
        cout << "4. Показать контакты\n";
        cout << "5. Выход\n";
        cout << "Введите действие, которое хотите выполнить: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                updateContact();
                break;
            case 4:
                showContacts();
                break;
            case 5:
                std::cout << "Выполняем выход";
                return 0;
            default:
                std::cout << "Попробуйте снова";
        }
    }

    return 0;
}