#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    int data;
    int priority;
};

Node pq[MAX];
int n = 0;

void array_insert(int i, Node x) {
    for (int j = n - 1; j >= i; j--) {
        pq[j + 1] = pq[j];
    }
    pq[i] = x;
}

Node array_delete(int i) {
    Node val = pq[i];
    for (int j = i; j < n - 1; j++) {
        pq[j] = pq[j + 1];
    }
    return val;
}

void enqueue(int data, int P) {
    if (n == MAX) {
        cout << "Priority Queue is Full!" << endl;
        return;
    }

    Node x;
    x.data = data;
    x.priority = P;

    int i = 0;
    while (i < n && P <= pq[i].priority) {
        i++;
    }
    array_insert(i, x);
    n++;
}

Node dequeue() {
    if (n == 0) {
        cout << "Priority Queue is Empty!" << endl;
        Node empty = {-1, -1};
        return empty;
    }
    Node val = array_delete(0);
    n--;
    return val;
}

void display() {
    cout << "Data\tPriority" << endl;
    for (int i = 0; i < n; i++) {
        cout << pq[i].data << "\t" << pq[i].priority << endl;
    }
}

int main() {
    enqueue(10, 2);
    enqueue(20, 5);
    enqueue(30, 5);
    enqueue(40, 1);
    enqueue(50, 3);

    display();

    cout << endl;
    Node d;
    d = dequeue();
    cout << "Deleted -> Data: " << d.data << ", Priority: " << d.priority << endl;
    d = dequeue();
    cout << "Deleted -> Data: " << d.data << ", Priority: " << d.priority << endl;

    cout << endl;
    display();

    return 0;
}