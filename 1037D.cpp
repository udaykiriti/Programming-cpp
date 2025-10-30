/******************************
 *    author:  -----          *
 *    created: 25 14:47:25    *
 ******************************/

// g++ -std=c++17 new.cpp -o new
// ./new
//g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name
//./file-name
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define vi vector<int>
#define pb push_back

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
   //solution here.........
    int n; cin >> n;
    vector<vi> g(n + 1);
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    debug(arr);
    debug(g);

    vi vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    queue<int> u;
    set<int> visited;
    int j = 1;
    u.push(1);

    while (!u.empty() && j != n) {
        int k = u.front();

        for (size_t i = (k == 1 ? 0 : 1); i < (g[k].size()); i++) {
            if (arr[k][vec[j]] != 1) {
                cout << "NO";
                return;
            }
            u.push(vec[j]);
            j++;
            if (j == n) {
                cout << "YES";
                return;
            }
        }
        visited.insert(k);
        u.pop();
    }
    debug("visited : \n");
    debug(visited);
    cout << "YES";
}

int main(){
    //freopen("in.txt","r",stdin);curl -f https://zed.dev/install.sh | sh
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}
