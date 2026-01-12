#include <iostream>
#include <string>
using namespace std;

#define MAX 5   // Maximum size of queue

class TicketQueue {
private:
    int front, rear;
    string tickets[MAX];

public:
    // Constructor
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Add a customer ticket (Enqueue)
    void enqueue(string ticket) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more tickets.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        tickets[rear] = ticket;
        cout << "Ticket added: " << ticket << endl;
    }

    // Process next ticket (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No ticket to process.\n";
            return;
        }
        cout << "Processing ticket: " << tickets[front] << endl;

        if (front == rear) {
            front = rear = -1;  // Queue becomes empty
        } else {
            front++;
        }
    }

    // Display all pending tickets
    void display() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }
        cout << "Pending Tickets:\n";
        for (int i = front; i <= rear; i++) {
            cout << "- " << tickets[i] << endl;
        }
    }

    // Cancel a specific ticket (Advanced)
    void cancelTicket(string ticket) {
        if (isEmpty()) {
            cout << "Queue is empty. No ticket to cancel.\n";
            return;
        }

        int pos = -1;
        for (int i = front; i <= rear; i++) {
            if (tickets[i] == ticket) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Ticket not found.\n";
            return;
        }

        for (int i = pos; i < rear; i++) {
            tickets[i] = tickets[i + 1];
        }
        rear--;

        if (rear < front) {
            front = rear = -1;
        }

        cout << "Ticket cancelled: " << ticket << endl;
    }
};

int main() {
    TicketQueue tq;

    tq.enqueue("Internet Issue");
    tq.enqueue("Login Problem");
    tq.enqueue("Payment Failure");

    tq.display();

    tq.dequeue();

    tq.display();

    tq.cancelTicket("Login Problem");

    tq.display();

    tq.dequeue();
    tq.dequeue();
    tq.dequeue();   // Testing empty queue

    return 0;
} 
