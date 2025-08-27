#include <iostream>

using namespace std;

const int MAX_SIZE = 10;
int stack[MAX_SIZE];
int top = -1;

void push() {
    if (top == MAX_SIZE - 1) {
        cout << "Stack is full. Cannot push element." << endl;
    } else {
        int value;
        cout << "Enter value to push: ";
        cin >> value;
        top++;
        stack[top] = value;
        cout << value << " pushed to stack." << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty. Cannot pop element." << endl;
    } else {
        cout << stack[top] << " popped from stack." << endl;
        top--;
    }
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty. No element to peek." << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Stack Operations Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if empty" << endl;
        cout << "4. Check if full" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << "Stack is empty? " << (isEmpty() ? "Yes" : "No") << endl;
                break;
            case 4:
                cout << "Stack is full? " << (isFull() ? "Yes" : "No") << endl;
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}