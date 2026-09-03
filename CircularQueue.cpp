#include <iostream>
#define SIZE 10
using namespace std;
class Queue
{
public:
    int data[SIZE];
    int front, rear;
    void initialize()
    {
        front=rear=-1;
    }
    bool isEmpty()
    {
        return front==-1;
    }
    bool isFull()
    {
        return (rear+1)%SIZE==front;
    }
    void enqueue(int info)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front==-1)
            front=0;
        rear=(rear+1)%SIZE;
        data[rear] = info;
    }
    int dequeue()
    {
        int item;
        if (front == -1)
        {
            cout<<endl<< "Queue is empty" << endl;
            return -1;
        }
        item=data[front];
        if (front==rear)
            front=rear= -1;
        else
            front=(front+1)%SIZE;
        return item;
    }
    void traverse()
    {
        if (isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        int i=front;
        while (i!=(rear))
        {
            cout<<data[i]<<" ";
            i = (i+1)%SIZE;
        }
        cout<<data[i]<<" ";
        cout << endl;
    }
};
int main()
{
    Queue Q;
    Q.initialize();
    int ch, info;
    do
    {
        cout << "\n1>Enqueue"
             << "\n2>Dequeue"
             << "\n3>Traverse"
             << "\n4>IsEmpty"
             << "\n5>IsFull"
             << "\n6>Exit"
             << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter info: ";
            cin>>info;
            Q.enqueue(info);
            cout<<"Front = "<<Q.front<< ", Rear = "<< Q.rear<< endl;
            break;
        case 2:
            info = Q.dequeue();
            if (info != -1)
                cout<<"Removed Element: " << info;
             cout<<"Front = "<<Q.front<< ", Rear = "<< Q.rear<< endl;
            break;
        case 3:
            Q.traverse();
            cout <<"Front = "<<Q.front<< ", Rear = "<< Q.rear<< endl;
            break;
        case 4:
            cout << "The queue is "<<(Q.isEmpty()?"Empty":"Not Empty") << endl;
            break;
        case 5:
            cout << "The queue is "<<(Q.isFull()?"Full":"Not Full") << endl;
            break;
        case 6:
            cout << endl << "This code is executed by Mr. XYZ with Roll No XXXXXX" << endl;
            break;
        default:
            cout << "Invalid Choice! Try again" << endl;
        }
    } while (ch != 6);
    return 0;
}
