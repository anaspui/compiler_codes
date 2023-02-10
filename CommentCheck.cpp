#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    cout << "Enter a statement: ";
    getline(cin, input);

    if (input.substr(0, 2) == "//")
    {
        cout << "This is a comment" << endl;
    }
    else if (input.substr(0, 2) == "/*" && input.substr(input.length() - 2, 2) == "*/")
    {
        cout << "This is a comment" << endl;
    }
    else
    {
        cout << "This is not a comment" << endl;
    }

    return 0;
}