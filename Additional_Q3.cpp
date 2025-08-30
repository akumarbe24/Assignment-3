#include <iostream>
#include <stack>
using namespace std;

void nextGreaterElement(int arr[], int n, int ans[]) {
    stack<int> st; 
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = arr[i]; 
        }
        st.push(i);
    }
    while (!st.empty()) {
        ans[st.top()] = -1;
        st.pop();
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans[n];
    nextGreaterElement(arr, n, ans);
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
