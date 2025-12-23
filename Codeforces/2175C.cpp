#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string s, t;
        cin >> s >> t;
        vector<int> cntT(26, 0), cntS(26, 0);
        for (char c : t) cntT[c - 'a']++;
        for (char c : s) cntS[c - 'a']++;
        bool ok = true;
        for (int i = 0; i < 26; ++i){
             if (cntS[i] > cntT[i]) { 
                ok = false; 
                break; 
            } 
        }
        if (!ok) {
            cout << "Impossible" << '\n';
            continue;
        }

        for (int i = 0; i < 26; ++i) cntT[i] -= cntS[i];
        string rem;
        rem.reserve(t.size() - s.size());
        for (int i = 0; i < 26; ++i) rem.append(cntT[i], char('a' + i));

        string ans;
        ans.reserve(t.size());
        size_t i = 0, j = 0;
        
        while (i < rem.size() && j < s.size()) {
            if (rem[i] < s[j]) {
                ans.push_back(rem[i++]);
            } else if (rem[i] > s[j]) {
                ans.push_back(s[j++]);
            } else {
                size_t ii = i, jj = j;
                bool takeS = false;
                while (ii < rem.size() && jj < s.size()) {
                    if (rem[ii] < s[jj]) { 
                        takeS = true; 
                        break; 
                    }
                    if (rem[ii] > s[jj]) { 
                        takeS = false; 
                        break; 
                    }
                    ++ii; ++jj;
                }
                if (ii == rem.size() && jj == s.size()) {
                    takeS = true;
                } else if (ii == rem.size()) {
                    takeS = false;
                } else if (jj == s.size()) {
                    takeS = true;
                }
                if (takeS) ans.push_back(s[j++]); else ans.push_back(rem[i++]);
            }
        }
        if (i < rem.size()) ans.append(rem.substr(i));
        if (j < s.size()) ans.append(s.substr(j));

        cout << ans << '\n';
    }
    return 0;
}