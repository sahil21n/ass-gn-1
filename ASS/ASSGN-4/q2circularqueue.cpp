#include <iostream>
using namespace std;

class CircularQueue {
public:
    int arr[100];
    int front;
    int rear;
    int capacity;

    CircularQueue() {
        front = -1;
        rear = -1;
        capacity = 100;
    }

    bool Is_Empty() {
        return (front == -1);
    }

    bool Is_Full() {
        return ((rear + 1) % capacity == front);
    }

    void enqueue(int val) {
        if (Is_Full()) {
            cout << "Queue is full, cannot enqueue" << endl;
            return;
        }
        if (Is_Empty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = val;
        cout << val << " enqueued." << endl;
    }

    void dequeue() {
        if (Is_Empty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return;
        }
        cout << arr[front] << " dequeued." << endl;
        if (front == rear) { // only one element
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    int peek() {
        if (Is_Empty()) {
            cout << "Queue empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (Is_Empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    int size() {
        if (Is_Empty()) return 0;
        if (rear >= front) return rear - front + 1;
        return capacity - (front - rear - 1);
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    while (true) {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Is Empty?\n";
        cout << "6. Is Full?\n";
        cout << "7. Size\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting..." << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            val = q.peek();
            if (val != -1) cout << "Front element: " << val << endl;
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.Is_Empty() ? "Queue is empty" : "Queue is not empty") << endl;
            break;
        case 6:
            cout << (q.Is_Full() ? "Queue is full" : "Queue is not full") << endl;
            break;
        case 7:
            cout << "Queue size: " << q.size() << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
