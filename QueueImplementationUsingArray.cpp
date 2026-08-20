#include <iostream>
#define SIZE 10
using namespace std;

class Queue
{
private:
    int data[SIZE];
    int front, rear;

public:
    // Constructor
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Check whether queue is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Check whether queue is full
    bool isFull()
    {
        return rear == SIZE - 1;
    }

    // Insert element
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        data[rear] = value;

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

        cout << "Removed element: " << data[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    // Display queue
    void traverse()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }
    void displayStatus(){
        cout<<"Front= "<<front
        <<", Rear= "<<rear<<endl;

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
            Q.displayStatus();
            break;

        case 5:
            if (Q.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is Not Full" << endl;
            Q.displayStatus();
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