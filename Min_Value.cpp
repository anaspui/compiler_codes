#include <iostream>
#include <array>
using namespace std;
double average_of_array(const array<double, 5>& arr) {
    double sum = 0;
    for (double element : arr) {
        sum += element;
    }
    return sum / arr.size();
}

int main() {
    array<double, 5> arr = {1.0, 2.0, 3.0, 4.0, 5.0};
    cout << "Average value of the elements in the array: " << average_of_array(arr) << endl;
    return 0;
}