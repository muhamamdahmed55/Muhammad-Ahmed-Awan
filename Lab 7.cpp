#include <iostream>
using namespace std;

class CSLLNode {
public:
    int id;
    string name, artist;
    float duration;
    CSLLNode* next;

    CSLLNode(int id, string n, string a, float d) {
        this->id = id;
        name = n;
        artist = a;
        duration = d;
        next = NULL;
    }
};

class CSLL {
private:
    CSLLNode* head;

public:
    CSLL() { head = NULL; }

    void insertAtBeginning(int id, string n, string a, float d) {
        CSLLNode* newNode = new CSLLNode(id, n, a, d);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            CSLLNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Track inserted at beginning!\n";
    }

    void insertAtEnd(int id, string n, string a, float d) {
        CSLLNode* newNode = new CSLLNode(id, n, a, d);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            CSLLNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Track inserted at end!\n";
    }

    void insertAtPosition(int pos, int id, string n, string a, float d) {
        if (pos == 1) {
            insertAtBeginning(id, n, a, d);
            return;
        }
        CSLLNode* newNode = new CSLLNode(id, n, a, d);
        CSLLNode* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Track inserted at position!\n";
    }

    void deleteFirst() {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        CSLLNode* temp = head;
        if (head->next == head) {
            head = NULL;
        } else {
            CSLLNode* last = head;
            while (last->next != head)
                last = last->next;
            head = head->next;
            last->next = head;
        }
        delete temp;
        cout << "First track deleted!\n";
    }

    void deleteLast() {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        CSLLNode* temp = head;
        if (temp->next == head) {
            head = NULL;
        } else {
            CSLLNode* prev = NULL;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
        }
        delete temp;
        cout << "Last track deleted!\n";
    }

    void deleteByID(int id) {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        CSLLNode *temp = head, *prev = NULL;
        if (temp->id == id) {
            deleteFirst();
            return;
        }
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
            if (temp->id == id) break;
        }
        if (temp->id != id) {
            cout << "Track not found!\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Track deleted by ID!\n";
    }

    void display() {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        CSLLNode* temp = head;
        cout << "\n----- SIMPLE PLAYLIST (CSLL) -----\n";
        do {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Artist: " << temp->artist
                 << " | Duration: " << temp->duration << endl;
            temp = temp->next;
        } while (temp != head);
        cout << "----------------------------------\n";
    }
};

class CDLLNode {
public:
    int id;
    string title, artist, album;
    float duration;
    CDLLNode *next, *prev;

    CDLLNode(int id, string t, string a, string al, float d) {
        this->id = id;
        title = t;
        artist = a;
        album = al;
        duration = d;
        next = prev = NULL;
    }
};

class CDLL {
private:
    CDLLNode* head;
    CDLLNode* current;

public:
    CDLL() {
        head = NULL;
        current = NULL;
    }

    void insertAtBeginning(int id, string t, string a, string al, float d) {
        CDLLNode* newNode = new CDLLNode(id, t, a, al, d);
        if (head == NULL) {
            head = newNode;
            newNode->next = newNode->prev = head;
        } else {
            CDLLNode* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Track inserted at beginning!\n";
    }

    void insertAtEnd(int id, string t, string a, string al, float d) {
        CDLLNode* newNode = new CDLLNode(id, t, a, al, d);
        if (head == NULL) {
            head = newNode;
            newNode->next = newNode->prev = head;
        } else {
            CDLLNode* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
        cout << "Track inserted at end!\n";
    }

    void insertAtPosition(int pos, int id, string t, string a, string al, float d) {
        if (pos == 1) {
            insertAtBeginning(id, t, a, al, d);
            return;
        }
        CDLLNode* newNode = new CDLLNode(id, t, a, al, d);
        CDLLNode* temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Track inserted at position!\n";
    }

    void deleteFirst() {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        CDLLNode* temp = head;
        if (head->next == head) {
            head = NULL;
        } else {
            CDLLNode* last = head->prev;
            head = head->next;
            head->prev = last;
            last->next = head;
        }
        delete temp;
        cout << "First track deleted!\n";
    }

    void deleteLast() {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        CDLLNode* last = head->prev;
        if (last == head) {
            head = NULL;
        } else {
            CDLLNode* newLast = last->prev;
            newLast->next = head;
            head->prev = newLast;
        }
        delete last;
        cout << "Last track deleted!\n";
    }

    void deleteByPosition(int pos) {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        if (pos == 1) {
            deleteFirst();
            return;
        }
        CDLLNode* temp = head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        cout << "Track deleted at position!\n";
    }

    void displayForward() {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        cout << "\n----- PREMIUM PLAYLIST (CDLL) -----\n";
        CDLLNode* temp = head;
        do {
            cout << "ID: " << temp->id
                 << " | Title: " << temp->title
                 << " | Artist: " << temp->artist
                 << " | Album: " << temp->album
                 << " | Duration: " << temp->duration << endl;
            temp = temp->next;
        } while (temp != head);
        cout << "-----------------------------------\n";
    }

    void displayReverse() {
        if (head == NULL) {
            cout << "Playlist empty!\n";
            return;
        }
        cout << "\n--- REVERSE PREMIUM PLAYLIST ---\n";
        CDLLNode* temp = head->prev;
        do {
            cout << "ID: " << temp->id
                 << " | Title: " << temp->title
                 << " | Artist: " << temp->artist
                 << " | Album: " << temp->album
                 << " | Duration: " << temp->duration << endl;
            temp = temp->prev;
        } while (temp != head->prev);
        cout << "--------------------------------\n";
    }

    void playNext() {
        if (current == NULL)
            current = head;
        else
            current = current->next;
        cout << "\nNow Playing:\n" << current->title << " - " << current->artist << endl;
    }

    void playPrevious() {
        if (current == NULL)
            current = head;
        else
            current = current->prev;
        cout << "\nNow Playing:\n" << current->title << " - " << current->artist << endl;
    }
};

int main() {
    CSLL csll;
    CDLL cdll;

    int mainChoice;

    while (true) {
        cout << "\n================ PLAYLIST MANAGER ================\n";
        cout << "1. Simple Playlist (CSLL)\n";
        cout << "2. Premium Playlist (CDLL)\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            int choice;

            while (true) {
                cout << "\n------- SIMPLE PLAYLIST (CSLL) -------\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert at Position\n";
                cout << "4. Delete First\n";
                cout << "5. Delete Last\n";
                cout << "6. Delete by ID\n";
                cout << "7. Display\n";
                cout << "8. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 8) break;

                int id, pos;
                string name, artist;
                float duration;

                switch (choice) {
                    case 1:
                        cout << "Enter ID: "; cin >> id;
                        cout << "Enter Name: "; cin >> name;
                        cout << "Enter Artist: "; cin >> artist;
                        cout << "Enter Duration: "; cin >> duration;
                        csll.insertAtBeginning(id, name, artist, duration);
                        break;

                    case 2:
                        cout << "Enter ID: "; cin >> id;
                        cout << "Enter Name: "; cin >> name;
                        cout << "Enter Artist: "; cin >> artist;
                        cout << "Enter Duration: "; cin >> duration;
                        csll.insertAtEnd(id, name, artist, duration);
                        break;

                    case 3:
                        cout << "Enter Position: "; cin >> pos;
                        cout << "Enter ID: "; cin >> id;
                        cout << "Enter Name: "; cin >> name;
                        cout << "Enter Artist: "; cin >> artist;
                        cout << "Enter Duration: "; cin >> duration;
                        csll.insertAtPosition(pos, id, name, artist, duration);
                        break;

                    case 4:
                        csll.deleteFirst();
                        break;

                    case 5:
                        csll.deleteLast();
                        break;

                    case 6:
                        cout << "Enter Track ID: ";
                        cin >> id;
                        csll.deleteByID(id);
                        break;

                    case 7:
                        csll.display();
                        break;

                    default:
                        cout << "Invalid choice!\n";
                }
            }
        }

        else if (mainChoice == 2) {
            int choice;

            while (true) {
                cout << "\n------- PREMIUM PLAYLIST (CDLL) -------\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert at Position\n";
                cout << "4. Delete First\n";
                cout << "5. Delete Last\n";
                cout << "6. Delete by Position\n";
                cout << "7. Display Forward\n";
                cout << "8. Display Reverse\n";
                cout << "9. Play Next\n";
                cout << "10. Play Previous\n";
                cout << "11. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 11) break;

                int id, pos;
                string title, artist, album;
                float duration;

                switch (choice) {
                    case 1:
                        cout << "Enter ID: "; cin >> id;
                        cout << "Enter Title: "; cin >> title;
                        cout << "Enter Artist: "; cin >> artist;
                        cout << "Enter Album: "; cin >> album;
                        cout << "Enter Duration: "; cin >> duration;
                        cdll.insertAtBeginning(id, title, artist, album, duration);
                        break;

                    case 2:
                        cout << "Enter ID: "; cin >> id;
                        cout << "Enter Title: "; cin >> title;
                        cout << "Enter Artist: "; cin >> artist;
                        cout << "Enter Album: "; cin >> album;
                        cout << "Enter Duration: "; cin >> duration;
                        cdll.insertAtEnd(id, title, artist, album, duration);
                        break;

                    case 3:
                        cout << "Enter Position: "; cin >> pos;
                        cout << "Enter ID: "; cin >> id;
                        cout << "Enter Title: "; cin >> title;
                        cout << "Enter Artist: "; cin >> artist;
                        cout << "Enter Album: "; cin >> album;
                        cout << "Enter Duration: "; cin >> duration;
                        cdll.insertAtPosition(pos, id, title, artist, album, duration);
                        break;

                    case 4:
                        cdll.deleteFirst();
                        break;

                    case 5:
                        cdll.deleteLast();
                        break;

                    case 6:
                        cout << "Enter Position: "; cin >> pos;
                        cdll.deleteByPosition(pos);
                        break;

                    case 7:
                        cdll.displayForward();
                        break;

                    case 8:
                        cdll.displayReverse();
                        break;

                    case 9:
                        cdll.playNext();
                        break;

                    case 10:
                        cdll.playPrevious();
                        break;

                    default:
                        cout << "Invalid choice!\n";
                }
            }
        }

        else if (mainChoice == 3) {
            cout << "Exiting... Goodbye Moon!\n";
            break;
        }

        else {
            cout << "Invalid option!\n";
        }
    }

    return 0;
}
