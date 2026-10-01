/*Program to finding nth Fibonacci number using recursion and improving it's runtime to save stack operations*/

#include <iostream>
using namespace std;

int fib(int n, int memo[])
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (memo[n] != 0)
        return memo[n];
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main()
{
    int n;
    cout << "Enter the position of the Fibonacci number you want: ";
    cin >> n;
    int memo[100] = {0};
    cout << "The " << n << "th Fibonacci number is: " << fib(n, memo) << endl;

    cout << "This code is implemented by Abhyudai Gupta " << endl;
}