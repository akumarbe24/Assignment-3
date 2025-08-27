#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool areParenthesesBalanced(const string& expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false;
            }
            char top_char = s.top();
            s.pop();
            if ((c == ')' && top_char != '(') ||
                (c == '}' && top_char != '{') ||
                (c == ']' && top_char != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[()]}]";
    
    if (areParenthesesBalanced(expr1)) {
        cout << expr1 << " has balanced parentheses." << endl;
    } else {
        cout << expr1 << " has unbalanced parentheses." << endl;
    }
    
    if (areParenthesesBalanced(expr2)) {
        cout << expr2 << " has balanced parentheses." << endl;
    } else {
        cout << expr2 << " has unbalanced parentheses." << endl;
    }
    
    return 0;
}