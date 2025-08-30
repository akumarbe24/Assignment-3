#include <iostream>
#include <stack>
using namespace std;

void dailyTemperatures(int temperatures[], int n, int answer[]) {
    stack<int> st; 
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top();
            st.pop();
            answer[idx] = i - idx; 
        }
        st.push(i);
    }
    while (!st.empty()) {
        answer[st.top()] = 0;
        st.pop();
    }
}

int main() {
    int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);
    int answer[n];
    dailyTemperatures(temperatures, n, answer);
    cout << "Answer: ";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
