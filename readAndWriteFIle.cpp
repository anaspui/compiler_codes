#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // Create and open a text file
  ofstream MyFile("myFile.txt");

  // Write to the file
  MyFile << "Hello..! How are you? :)\n";

  // Close the file
  MyFile.close();

  string myText;

  // Read from the text file
    ifstream MyReadFile("myFile.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText;
    }

    // Close the file
    MyReadFile.close();
}
