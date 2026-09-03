#include <iostream>
using namespace std;

class Queue
{
private:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    // Constructor
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Check whether queue is empty
    bool isEmpty()
    {
        return front == NULL;
    }

    // Insert element
    void enqueue(int value)
    {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Element inserted successfully" << endl;
    }

    // Delete element
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node* temp = front;

        cout << "Removed element: " << front->data << endl;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }

    // Display queue
    void traverse()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node* temp = front;

        cout << "Queue elements: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Display front and rear
    void displayStatus()
    {
        if (isEmpty())
        {
            cout << "Front = NULL, Rear = NULL" << endl;
        }
        else
        {
            cout << "Front = " << front->data
                 << ", Rear = " << rear->data << endl;
        }
    }
};

int main()
{
    Queue Q;
    int choice, Value;

    do
    {
        cout << "\n----- QUEUE MENU -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display Status" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> Value;
            Q.enqueue(Value);
            Q.displayStatus();
            break;

        case 2:
            Q.dequeue();
            Q.displayStatus();
            break;

        case 3:
            Q.traverse();
            Q.displayStatus();
            break;

        case 4:
            if (Q.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is Not Empty" << endl;
            break;

        case 5:
            cout << "Queue using Linked List does not have a fixed size." << endl;
            cout << "It is Full only when memory is unavailable." << endl;
            break;

        case 6:
            Q.displayStatus();
            break;

        case 7:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}