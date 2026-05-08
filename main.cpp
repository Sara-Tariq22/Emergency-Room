#include <iostream>
#include <string>

using namespace std;

struct Patient {
    string name;
    int priority;
    Patient* next;
};

class EmergencyRoom {
private:
    Patient* head;

public:
    EmergencyRoom() { head = nullptr; }

    void admitPatient(string name, int p) {
        Patient* newP = new Patient{name, p, nullptr};

        if (head == nullptr || p < head->priority) {
            newP->next = head;
            head = newP;
        } else {
            Patient* temp = head;
            while (temp->next != nullptr && temp->next->priority <= p) {
                temp = temp->next;
            }
            newP->next = temp->next;
            temp->next = newP;
        }
        cout << "\n[Success] " << name << " added to the queue." << endl;
    }

    void treatNext() {
        if (head == nullptr) {
            cout << "\n[Alert] No patients to treat!" << endl;
            return;
        }
        Patient* temp = head;
        cout << "\n[Doctor] Now treating: " << temp->name << " (Priority " << temp->priority << ")" << endl;
        head = head->next;
        delete temp;
    }

    void displayQueue() {
        cout << "\n--- CURRENT WAITING ROOM ---" << endl;
        if (head == nullptr) {
            cout << "(Empty)" << endl;
            return;
        }
        Patient* temp = head;
        while (temp != nullptr) {
            cout << "[" << temp->name << " | P:" << temp->priority << "] -> ";
            temp = temp->next;
        }
        cout << "END" << endl;
    }
};

int main() {
    EmergencyRoom er;
    int choice;
    string name;
    int priority;

    while (true) {
        cout << "\n=== ER TRIAGE SYSTEM ===";
        cout << "\n1. Admit New Patient";
        cout << "\n2. Treat Next Patient";
        cout << "\n3. View Waiting Room";
        cout << "\n4. Exit";
        cout << "\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Patient Name: ";
            cin.ignore(); // Clear buffer
            getline(cin, name);
            cout << "Enter Priority (1=Critical, 5=Minor): ";
            cin >> priority;

            if(priority < 1 || priority > 5) {
                cout << "Invalid priority! Setting to 5 (Minor)." << endl;
                priority = 5;
            }
            er.admitPatient(name, priority);

        } else if (choice == 2) {
            er.treatNext();
        } else if (choice == 3) {
            er.displayQueue();
        } else if (choice == 4) {
            cout << "Closing system..." << endl;
            break;
        } else {
            cout << "Invalid selection!" << endl;
        }
    }

    return 0;
}
