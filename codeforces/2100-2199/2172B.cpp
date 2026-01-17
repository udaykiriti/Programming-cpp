
// g++ -std=c++17 new.cpp -o new
// ./new
//g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name 
//./file-name
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif


using ld = long double;

struct Event {
    long long pos;
    int type;      
    ld value;
    int idx;       
};


void solve(){
   //soLuSHoNN hErE.........
   int n, m;
    long long L, x, y;
    cin >> n >> m >> L >> x >> y;

    vector<Event> ev;
    ev.reserve(2*n + m);

    for (int i = 0; i < n; i++) {
        long long s, t;
        cin >> s >> t;

        ld cost = (ld)(t - s) / x + (ld)(L - t) / y;

        ev.push_back({s, 0, cost, -1});  
        ev.push_back({t, 2, cost, -1});  
    }

    vector<long long> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        ev.push_back({p[i], 1, 0, i});
    }

    sort(ev.begin(), ev.end(), [](auto &a, auto &b) {
        if (a.pos != b.pos) return a.pos < b.pos;
        return a.type < b.type;
    });

    multiset<ld> active;
    vector<ld> ans(m);

    for (auto &e : ev) {
        if (e.type == 0) {
            active.insert(e.value);
        } 
        else if (e.type == 2) {
            auto it = active.find(e.value);
            if (it != active.end()) active.erase(it);
        } 
        else {
            long long pos = e.pos;
            ld walk = (ld)(L - pos) / y;

            if (active.empty()) ans[e.idx] = walk;
            else ans[e.idx] = min(walk, *active.begin());
        }
    }

    cout << setprecision(12) << defaultfloat;
    for (auto &v : ans) cout << (double)v << "\n";
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}