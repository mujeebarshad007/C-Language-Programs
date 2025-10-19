#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

class StringQueue {
    string arr[SIZE];
    int front, rear;

public:
    StringQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert \"" << value << "\"\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << "\"" << value << "\" enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue.\n";
            return;
        }
        cout << "\"" << arr[front] << "\" dequeued.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void displayReverse() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements in reverse: ";
        for (int i = rear; i >= front; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StringQueue q;
    int choice;
    string value;

    do {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue String\n2. Dequeue String\n3. Display Queue\n4. Display Reverse Queue\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter string to enqueue: ";
                cin.ignore(); // Clear newline
                getline(cin, value);
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.displayReverse();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
