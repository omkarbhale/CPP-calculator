#include <iostream>

using namespace std;

int main() {

    float first_number;
    float second_number;
    char operation;

    cout << "Enter operation to perform: A/S/M/D\n";
    cin >> operation;
    cout << "Enter first number\n";
    cin >> first_number;
    cout << "Enter second number\n";
    cin >> second_number;

    if(operation == 'A' || operation == 'a') {
        cout << "Output is " << first_number+second_number;
    }
    if(operation == 'S' || operation == 's') {
        cout << "Output is " << first_number-second_number;
    }
    if(operation == 'M' || operation == 'm') {
        cout << "Output is " << first_number*second_number;
    }
    if(operation == 'D' || operation == 'd') {
        cout << "Output is " << first_number/second_number;
    }
}