#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> vec(n);
    vector<int> res(n, -1);
    
    for (auto &x : vec) cin >> x;
    
    stack<int> st;
    for (int i = vec.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= vec[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(vec[i]);
    }
    
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
