/**
 * Source: http://codeforces.com/blog/entry/12143
 * Time: O(N)
 * Description: length of largest palindrome centered at each character of
 * string and between every consecutive pair
 * Verification: http://www.spoj.com/problems/MSUBSTR/
 */

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define FOR(i,a,b) for(int i = (a) ; i < (b) ; i++)

vi manacher(const string& _S) {
    string S = "@";
    for (char c : _S) {
        S += c;
        S += '#';
    }
    S += '&';

    int n = (int)S.size();
    vi ans(n - 1);

    int lo = 0, hi = 0;
    FOR (i ,0, n - 1) {
        if (i != 1)
            ans[i] = min(hi - i, ans[hi - i + lo]);

        while (S[i - ans[i] - 1] == S[i + ans[i] + 1])
            ++ans[i];

        if (i + ans[i] > hi) {
            lo = i - ans[i];
            hi = i + ans[i];
        }
    }

    ans.erase(ans.begin());

    for (int i = 0; i < (int)ans.size(); i++)
        if (i % 2 == ans[i] % 2)
            ++ans[i];

    return ans;
}
