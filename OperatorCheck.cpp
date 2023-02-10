#include <iostream>
#include <string>

using namespace std;

bool isOperator(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
    return true;
  }
  return false;
}

int main() {
  string input;
  cout << "Input: ";
  cin>>input;
  int count = 0;
  for (int i = 0; i < input.length(); i++) {
    if (isOperator(input[i])) {
      count++;
      cout << "Operator " << count << ": " << input[i] << endl;
    }
  }
  cout << "Number of operators: " << count << endl;
  return 0;
}