#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[1000], B[1000];
    for (int i = 0; i < n; i++) cin >> A[i];
    stack<int> S;
    int expected = 1, bIndex = 0;
    for (int i = 0; i < n; i++) {
        S.push(A[i]);
        while (!S.empty() && S.top() == expected) {
            B[bIndex++] = S.top();
            S.pop();
            expected++;
        }
    }
    while (!S.empty() && S.top() == expected) {
        B[bIndex++] = S.top();
        S.pop();
        expected++;
    }
    if (bIndex == n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
