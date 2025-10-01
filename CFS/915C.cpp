#include <bits/stdc++.h>
using namespace std;

string solve(string s, string s1) {
    int n = s.size();
    if (n < (int)s1.size()) {
        sort(s.rbegin(), s.rend());
        return s;
    }

    sort(s.begin(), s.end());
    string best = "";
    function<bool(int,string,multiset<char>&,bool)> dfs =
        [&](int pos, string curr, multiset<char>& ms, bool tight) -> bool {
            if (pos == (int)s1.size()) {
                best = curr;
                return true;
            }
            char limit = tight ? s1[pos] : '9';
            for (char c = limit; c >= '0'; c--) {
                auto it = ms.find(c);
                if (it == ms.end()) continue;
                curr.push_back(c);
                ms.erase(it);
                if (tight && c == limit) {
                    if (dfs(pos+1, curr, ms, true)) return true;
                } else {
                    string temp = curr;
                    for (auto it2 = ms.rbegin(); it2 != ms.rend(); ++it2)
                        temp.push_back(*it2);
                    best = temp;
                    return true;
                }
                ms.insert(c);
                curr.pop_back();
            }
            return false;
        };

    multiset<char> ms(s.begin(), s.end());
    dfs(0, "", ms, true);
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, s1;
    cin >> s >> s1;
    cout << solve(s, s1) << "\n";
    return 0;
}
