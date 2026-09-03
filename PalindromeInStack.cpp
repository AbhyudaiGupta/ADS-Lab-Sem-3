/*WAP to check if the given number or word is a palindrome using stack */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    stack<char> s;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string reversed = "";
    while (!s.empty())
    {
        reversed += s.top();
        s.pop();
    }

    if (str == reversed)
    {
        cout << str << " is a palindrome." << endl;
    }
    else
    {
        cout << str << " is not a palindrome." << endl;
    }
}