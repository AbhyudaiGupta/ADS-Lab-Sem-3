#include <iostream>
using namespace std;
int n = 5;
int stack[5];
int top = -1;

bool isEmpty()
{
    return top <= -1;
}
bool isFull()
{
    return top >= n - 1;
}

void push(int ITEM)
{
    if (isFull())
    {
        cout << "Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = ITEM;
    }
}
void pop()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
    }
    else
    {
        cout << "The element is" << stack[top] << endl;
        top--;
    }
}
void Traverse()
{
    int i;
    if (!isEmpty())
    {
        cout << "Stack elements are: ";
        for (i = top; i > 0; i--)
        {
            cout << stack[i] << " ";
        }

        cout << endl;
        cout << "Top element is: " << stack[top] << endl;
    }

    else
    {
        cout << "Stack is empty";
    }
}

int main()
{
    int ch, ITEM;
    cout << "1.Push" << endl;
    cout << "2.Pop" << endl;
    cout << "3.Traverse" << endl;
    cout << "4.Exit" << endl;
    do
    {
        cout << "Enter choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "Enter ITEM:" << endl;
            cin >> ITEM;
            push(ITEM);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            Traverse();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice";
        }
        }
    } while (ch != 4);

    return 0;
}