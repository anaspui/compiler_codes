/*read space separated text file in c++*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream input("split_text.txt"); //ifstream, ofstream
    string line;
    while (getline(input, line, ' ')) {
        cout << line << '\n';
    }
    return 0;

}
