//reverse a number using recursion
#include <iostream>
using namespace std;

int reverseNumber(int num, int reversed) {
    if (num == 0) {
        return reversed;
    }
    return reverseNumber(num / 10, reversed * 10 + num % 10);
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int reversed = reverseNumber(num, 0);
    cout << "Reversed number: " << reversed << endl;
    return 0;
}