#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> s;

    for (char ch : exp)
    {
        if (isdigit(ch))
            s.push(ch - '0');

        else
        {
            if (s.size() < 2)
            {
                cout << "Invalid expression!";
                return 0;
            }

            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            switch (ch)
            {
                case '+':
                    s.push(a + b);
                    break;

                case '-':
                    s.push(a - b);
                    break;

                case '*':
                    s.push(a * b);
                    break;

                case '/':
                    if (b == 0)
                    {
                        cout << "Division by zero!";
                        return 0;
                    }
                    s.push(a / b);
                    break;

                case '^':
                    s.push((int)pow(a, b));
                    break;
            }
        }
    }

    return s.top();
}

int main()
{
    string exp;

    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result: " << evaluatePostfix(exp) << endl;

    return 0;
}
