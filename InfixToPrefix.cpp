#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool isRightAssociative(char op)
{
    return op == '^';
}

int main()
{
    string Q, P;
    cout << "Enter infix expression: ";
    cin >> Q;

    // Reverse the infix expression
    reverse(Q.begin(), Q.end());

    // Swap '(' and ')'
    for (int i = 0; i < Q.length(); i++)
    {
        if (Q[i] == '(')
            Q[i] = ')';
        else if (Q[i] == ')')
            Q[i] = '(';
    }

    stack<char> s;

    for (int i = 0; i < Q.length(); i++)
    {
        char ch = Q[i];

        if (isalnum(ch))
        {
            P = P + ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                P = P + s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(ch) ||
                    (precedence(s.top()) == precedence(ch) &&
                     isRightAssociative(ch))))
            {
                P = P + s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        P = P + s.top();
        s.pop();
    }

    // Reverse postfix to get prefix
    reverse(P.begin(), P.end());

    cout << "Prefix expression : " << P << endl;

    return 0;
}