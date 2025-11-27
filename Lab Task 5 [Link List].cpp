#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int patientID;
    string name;
    Node* next;

    Node(int id, string n) {
        patientID = id;
        name = n;
        next = NULL;
    }
};

class PatientList {
private:
    Node* head;

public:
    PatientList() {
        head = NULL;
    }

    
    void insertAtEnd(int id, string name) {
        Node* newNode = new Node(id, name);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    
    void insertAtBeginning(int id, string name) {
        Node* newNode = new Node(id, name);
        newNode->next = head;
        head = newNode;
    }

  
    void searchPatient(int id) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->patientID == id) {
                cout << "Patient Found!\n";
                cout << "ID: " << temp->patientID << "\n";
                cout << "Name: " << temp->name << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Patient with ID " << id << " not found.\n";
    }

    
    void deletePatient(int id) {
        if (head == NULL) {
            cout << "No patients in the list.\n";
            return;
        }

      
        if (head->patientID == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Patient removed successfully.\n";
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->patientID != id) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Patient not found.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Patient removed successfully.\n";
    }

    
    void display() {
        if (head == NULL) {
            cout << "No patients currently in hospital.\n";
            return;
        }

        Node* temp = head;
        cout << "\nCurrent Patients:\n";
        while (temp != NULL) {
            cout << "ID: " << temp->patientID 
                 << " | Name: " << temp->name << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    PatientList hospital;
    int choice, id;
    string name;

    while (true) {
        cout << "\n--- HOSPITAL PATIENT MANAGEMENT ---\n";
        cout << "1. Add Patient (End)\n";
        cout << "2. Add Emergency Patient (Beginning)\n";
        cout << "3. Search Patient\n";
        cout << "4. Remove Treated Patient\n";
        cout << "5. Display All Patients\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                cout << "Enter Patient Name: ";
                cin.ignore();
                getline(cin, name);
                hospital.insertAtEnd(id, name);
                break;

            case 2:
                cout << "Enter Patient ID: ";
                cin >> id;
                cout << "Enter Patient Name: ";
                cin.ignore();
                getline(cin, name);
                hospital.insertAtBeginning(id, name);
                break;

            case 3:
                cout << "Enter Patient ID to search: ";
                cin >> id;
                hospital.searchPatient(id);
                break;

            case 4:
                cout << "Enter Patient ID to remove: ";
                cin >> id;
                hospital.deletePatient(id);
                break;

            case 5:
                hospital.display();
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
