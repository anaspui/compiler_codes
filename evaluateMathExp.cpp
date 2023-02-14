// C++ program to evaluate a given expression
#include <iostream>
using namespace std;

// A utility function to check if a given character is operand
bool isOperand(char c) { return (c >= '0' && c <= '9'); }

// utility function to find value of and operand
int value(char c) { return (c - '0'); }

// This function evaluates simple expressions. It returns -1 if the
// given expression is invalid.
int evaluate(char *exp)
{
    // Base Case: Given expression is empty
    if (*exp == '\0')  return -1;

    // The first character must be an operand, find its value
    int res = value(exp[0]);

    // Traverse the remaining characters in pairs
    for (int i = 1; exp[i]; i += 2)
    {
        // The next character must be an operator, and
        // next to next an operand
        char opr = exp[i], opd = exp[i+1];

        // If next to next character is not an operand
        if (!isOperand(opd))  return -1;

        // Update result according to the operator
        if (opr == '+')       res += value(opd);
        else if (opr == '-')  res -= value(opd);
        else if (opr == '*')  res *= value(opd);
        else if (opr == '/')  res /= value(opd);

        // If not a valid operator
        else                  return -1;
    }
    return res;
}

// Driver program to test above function
int main()
{
    char expr1[] = "1+2*5+3";
    int res = evaluate(expr1);
    (res == -1)? cout << expr1 << " is " << "Invalid\n":
                 cout << "Value of " << expr1 << " is " << res << endl;

    char expr2[] = "1+2*3";
    res = evaluate(expr2);
    (res == -1)? cout << expr2 << " is " << "Invalid\n":
                 cout << "Value of " << expr2 << " is " << res << endl;

    char expr3[] = "4-2+6*3";
    res = evaluate(expr3);
    (res == -1)? cout << expr3 << " is " << "Invalid\n":
                 cout << "Value of " << expr3 << " is " << res << endl;

    char expr4[] = "1++2";
    res = evaluate(expr4);
    (res == -1)? cout << expr4 << " is " << "Invalid\n":
                 cout << "Value of " << expr4 << " is " << res << endl;
    return 0;
}
