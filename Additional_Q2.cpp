#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<long long> st;
    long long minEle;

public:
    void push(long long x) {
        if (st.empty()) {
            st.push(x);
            minEle = x;
        } else {
            if (x >= minEle) {
                st.push(x);
            } else {
         
                st.push(2 * x - minEle);
                minEle = x;
            }
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        long long topVal = st.top();
        st.pop();

        if (topVal < minEle) {
            minEle = 2 * minEle - topVal;
        }
    }

    long long top() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        long long topVal = st.top();
        if (topVal >= minEle) {
            return topVal;
        } else {
            return minEle;
        }
    }

    long long getMin() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minEle;
    }
    bool empty() {
        return st.empty();
    }
};

int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    cout << "Min: " << s.getMin() << "\n"; 
    s.push(2);
    s.push(1);
    cout << "Min: " << s.getMin() << "\n"; 
    s.pop();
    cout << "Min: " << s.getMin() << "\n"; 
    s.pop();
    cout << "Top: " << s.top() << "\n";   
    cout << "Min: " << s.getMin() << "\n";
    return 0;
}
