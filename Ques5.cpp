#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

bool isOperand(char c) {
    return isdigit(c);
}

double evaluatePostfix(const string& postfix) {
    stack<double> s;
    for (char c : postfix) {
        if (isOperand(c)) {
            s.push(c - '0');
        } else {
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();

            switch (c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    string postfix_expr = "23+5*";
    cout << "Postfix expression: " << postfix_expr << endl;
    double result = evaluatePostfix(postfix_expr);
    cout << "Result: " << result << endl;
    return 0;
}