/*
g++ -std=c++17 new.cpp -o new
./new
g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name 
./file-name
*/

#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif


struct Truck {
    int v;
    int c;
    int l;
    int r;
    int idx;
};


void solve(){
   //soLuSHoNN hErE.........
    int n;
    cin >> n;
    vector<Truck> trucks(n);
    for (int i = 0; i < n; i++) {
        cin >> trucks[i].v >> trucks[i].c >> trucks[i].l >> trucks[i].r;
        trucks[i].idx = i + 1;
    }

    map<int, vector<Truck>> groups;
    for (auto& t : trucks) {
        int S = t.l + t.c + t.r;
        groups[S].push_back(t);
    }

    vector<int> best_seq;
    long long best_val = 0;

    for (auto& p : groups) {
        int S = p.first;
        vector<Truck>& group = p.second;
        sort(group.begin(), group.end(), [](const Truck& a, const Truck& b) {
            return a.idx < b.idx;
        });

        map<int, long long> dp_val;
        map<int, int> prev_state;
        map<int, int> last_truck_id;

        dp_val[0] = 0;

        for (auto& t : group) {
            if (dp_val.find(t.l) != dp_val.end()) {
                int x = t.l + t.c;
                long long candidate = dp_val[t.l] + t.v;
                if (dp_val.find(x) == dp_val.end() || candidate > dp_val[x]) {
                    dp_val[x] = candidate;
                    prev_state[x] = t.l;
                    last_truck_id[x] = t.idx;
                }
            }
        }

        if (dp_val.find(S) != dp_val.end()) {
            if (dp_val[S] > best_val) {
                best_val = dp_val[S];
                vector<int> seq;
                int x = S;
                while (x != 0) {
                    seq.push_back(last_truck_id[x]);
                    x = prev_state[x];
                }
                reverse(seq.begin(), seq.end());
                best_seq = seq;
            }
        }
    }

    cout << best_seq.size() << endl;
    if (best_seq.size() > 0) {
        for (int i = 0; i < best_seq.size(); i++) {
            if (i > 0) cout << " ";
            cout << best_seq[i];
        }
        cout << endl;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}