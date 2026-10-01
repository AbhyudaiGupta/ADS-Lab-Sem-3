#include <iostream>
using namespace std;

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Insert from front
void insertFront(int value)
{
    if ((front == 0 && rear == SIZE - 1) || front == rear + 1)
    {
        cout << "Deque is Full\n";
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }

    deque[front] = value;
}

// Insert from rear
void insertRear(int value)
{
    if ((front == 0 && rear == SIZE - 1) || front == rear + 1)
    {
        cout << "Deque is Full\n";
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

// Delete from front
void deleteFront()
{
    if (front == -1)
    {
        cout << "Deque is Empty\n";
        return;
    }

    cout << "Deleted: " << deque[front] << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Delete from rear
void deleteRear()
{
    if (front == -1)
    {
        cout << "Deque is Empty\n";
        return;
    }

    cout << "Deleted: " << deque[rear] << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}

// Display deque
void display()
{
    if (front == -1)
    {
        cout << "Deque is Empty\n";
        return;
    }

    cout << "Deque: ";

    int i = front;

    while (true)
    {
        cout << deque[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n----- DEQUE MENU -----\n";
        cout << "1. Insert from Front\n";
        cout << "2. Insert from Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertFront(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertRear(value);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
            display();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}