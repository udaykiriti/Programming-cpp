#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F')
            pos.push_back(i);
    }
    int k = pos.size();
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    bool done = true;
    for (int i = 0; i < k; i++) {
        if (pos[i] != i) {
            done = false;
            break;
        }
    }
    if (done) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> dp(k);
    dp[0] = pos[0] - 0;

    for (int i = 1; i < k; i++) {
        dp[i] = max(dp[i - 1] + 1, pos[i] - i);
    }

    cout << dp[k - 1] << endl;
    return 0;
}