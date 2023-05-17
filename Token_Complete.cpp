#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <stack>

using namespace std;

bool is_valid_identifier(string word) {
    if (!isalpha(word[0]) && word[0] != '_') {
        return false;
    }
    for (int i = 1; i < word.length(); i++) {
        if (!isalnum(word[i]) && word[i] != '_') {
            return false;
        }
    }
    unordered_set<string> keywords = {"if", "else", "for", "while", "do", "switch", "case", "default", "return", "break", "continue", "const", "static", "typedef", "sizeof", "struct", "class", "namespace", "using", "template"};
    if (keywords.count(word) > 0) {
        return false;
    }
    return true;
}

bool is_valid_operator(string word) {
    unordered_set<string> operators = {"+", "-", "*", "/", "%", "=", "+=", "-=", "*=", "/=", "%=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "<<", ">>", "++", "--", "->", ".", "->*"};
    return operators.count(word) > 0;
}

bool is_valid_preprocessor(string word) {
    return word[0] == '#';
}

bool is_valid_function(string word) {
    if (word[word.length() - 1] != '(') {
        return false;
    }
    string identifier = word.substr(0, word.length() - 1);
    return is_valid_identifier(identifier);
}

bool is_valid_math_expression(string line) {
    for (char c : line) {
        if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')') {
            return false;
        }
    }
    stack<char> parentheses;
    for (char c : line) {
        if (c == '(') {
            parentheses.push(c);
        } else if (c == ')') {
            if (parentheses.empty() || parentheses.top() != '(') {
                return false;
            }
            parentheses.pop();
        }
    }
    return parentheses.empty();
}

bool is_valid_comment(string line) {
    if (line.substr(0, 2) != "//") {
        return false;
    }
    string sentence = line.substr(2);
    if (sentence[sentence.length() - 1] != '.') {
        return false;
    }
    bool has_space = false;
    for(char c : sentence) {
    if (isspace(c)) {
        has_space = true;
        break;
    }
}
if (!has_space) {
    return false;
}
return true;
}

int main() {
ifstream input_file("file.cpp");
if (!input_file.is_open()) {
cerr << "Failed to open input file" << endl;
return 1;
}
int num_identifiers = 0;
int num_operators = 0;
int num_preprocessors = 0;
int num_functions = 0;
int num_comments = 0;
int num_math_expressions = 0;


string line;
while (getline(input_file, line)) {
    string word;
    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (isalnum(c) || c == '_') {
            word += c;
        } else {
            if (word.length() > 0) {
                if (is_valid_identifier(word)) {
                    num_identifiers++;
                } else if (is_valid_operator(word)) {
                    num_operators++;
                } else if (is_valid_preprocessor(word)) {
                    num_preprocessors++;
                } else if (is_valid_function(word)) {
                    num_functions++;
                }
                word.clear();
            }
        }
    }
    if (word.length() > 0) {
        if (is_valid_identifier(word)) {
            num_identifiers++;
        } else if (is_valid_operator(word)) {
            num_operators++;
        } else if (is_valid_preprocessor(word)) {
            num_preprocessors++;
        } else if (is_valid_function(word)) {
            num_functions++;
        }
    }

    if (is_valid_math_expression(line)) {
        num_math_expressions++;
    }

    if (is_valid_comment(line)) {
        num_comments++;
    }

    if (line.find(";") != string::npos && line[line.length() - 1] != ';') {
        cerr << "Syntax error: missing semicolon at the end of line" << endl;
    }

    stack<char> parentheses;
    for (char c : line) {
        if (c == '(') {
            parentheses.push(c);
        } else if (c == ')') {
            if (parentheses.empty() || parentheses.top() != '(') {
                cerr << "Syntax error: mismatched parentheses" << endl;
            } else {
                parentheses.pop();
            }
        }
    }
    if (!parentheses.empty()) {
        cerr << "Syntax error: mismatched parentheses" << endl;
    }
}

cout << "Number of unique valid identifiers: " << num_identifiers << endl;
cout << "Number of valid operators: " << num_operators << endl;
cout << "Number of valid preprocessors: " << num_preprocessors << endl;
cout << "Number of valid functions: " << num_functions << endl;
cout << "Number of valid comments: " << num_comments <<endl;
}
