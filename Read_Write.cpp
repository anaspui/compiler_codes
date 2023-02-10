#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
  string name;
  int marks;
};

int main() {
  int n;
  cout << "Enter the number of students: ";
  cin >> n;
  Student students[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter the name " << i + 1 << ": ";
    cin >> students[i].name;
    cout << "Enter the marks " << i + 1 << ": ";
    cin >> students[i].marks;
  }

  ofstream file("students.txt");
  if (file.is_open()) {
    for (int i = 0; i < n; i++) {
      file << students[i].name << " " << students[i].marks << endl;
    }
    file.close();
  } else {
    cout << "Unable to open file" << endl;
  }

  ifstream readFile("students.txt");
  if (readFile.is_open()) {
    cout << "Reading from file:" << endl;
    while (readFile >> students[n].name >> students[n].marks) {
      cout << students[n].name << " " << students[n].marks << endl;
    }
    readFile.close();
  } else {
    cout << "Unable to open file" << endl;
  }

  return 0;
}
