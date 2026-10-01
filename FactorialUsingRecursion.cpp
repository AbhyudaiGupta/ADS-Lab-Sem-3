#include <iostream>
using namespace std;

int factorialNonTail(int n)
{
    if (n == 0)
        return 1;

    return n * factorialNonTail(n - 1);
}

int factorialTail(int n, int result)
{
    if (n == 0)
        return result;

    return factorialTail(n - 1, result * n);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial using Non-Tail Recursion = "
         << factorialNonTail(n) << endl;

    cout << "Factorial using Tail Recursion = "
         << factorialTail(n, 1) << endl;

    cout << "This code is implemented by Abhyudai Gupta " << endl;
}