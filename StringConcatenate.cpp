#include <iostream>
#include <string>
using namespace std;
int main() {

    string first_name, last_name;

    cout << "First name: ";
    cin >> first_name;
    cout << "Last name: ";
    cin >> last_name;

    string full_name = first_name + " " + last_name;
    cout << "Your full name is: " << full_name << endl;

    return 0;
}
