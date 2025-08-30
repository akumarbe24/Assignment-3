#include <bits/stdc++.h>
using namespace std;

void nearestSmallerToLeft(int A[], int n) {
    int result[n];  
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        } else {
            result[i] = -1; 
        }

        st.push(A[i]);
    }

    cout << "Nearest smaller to left: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {4, 5, 2, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);

    nearestSmallerToLeft(A, n);

    return 0;
}
