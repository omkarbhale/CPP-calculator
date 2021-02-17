#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
bool validateCharachters(string input) {
    for (int i = 0; i < input.length(); i++){
        if (!(input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' ||
        input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9' || input[i] == '0' ||
        input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')){
            return false; // error
        }
    }
    return true;
}

string removeSpaces(string input) {
    string output = "";
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == ' ') {
        } else {
            output += input[i];
        }
    }
    return output;
}

bool isOperation(char in) {
    return (in == '+' || in == '-' || in == '/' || in == '*');
}

int validateExpression(string expression) {
    if(isOperation(expression[0]) || isOperation(expression[expression.length()-1])) {
        return 1; // operation at start or end
    }
    for(int i = 1; i < expression.length()-2; i++) {
        if(isOperation(expression[i]) && isOperation(expression[i+1])) {
            return 2; // consecutive operands
        }
    }
    return 0; // correct syntax
}

void handleError(string error) {
    cout << error << "Press any key to exit.";
    getch();
    exit(0);
}


int main() {

    // Get a line as input.
    string input_expression;
    getline(cin, input_expression);

    // remove all spaces
    input_expression = removeSpaces(input_expression);

    // cout << input_expression;

    // check if all characters are numbers or strings
    if(!validateCharachters(input_expression)) {
        string error = "\nYou used character other than numbers, and 4 operations!\n";
        handleError(error);
    }
    // check if there is operation sign at beggining or end
    if(validateExpression(input_expression) == 1) {
        string error = "\nYou used operation sign at start or end.\n";
        handleError(error);
    }
    // check if there are 2 or more consecutive operation signs.
    if(validateExpression(input_expression) == 2) {
        string error = "\nYou used 2 or more consecutive operation signs.\n";
        handleError(error);
    }

    // At this point, the expression is perfect.
    
}
