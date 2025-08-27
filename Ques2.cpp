#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseString(const string& str) {
    stack<char> s;
    for (char c : str) {
        s.push(c);
    }
    
    string reversed_str = "";
    while (!s.empty()) {
        reversed_str += s.top();
        s.pop();
    }
    return reversed_str;
}

int main() {
    string str = "DataStructure";
    cout << "Original string: " << str << endl;
    string reversed = reverseString(str);
    cout << "Reversed string: " << reversed << endl;
    return 0;
}