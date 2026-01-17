/*
              __                   __
             ( _)                 ( _)
            / / \               / /\_\_
           / /   \             / / | \ \
          / /     \           / /  |\ \ \
         /  /   ,  \ ,       / /   /|  \ \
        /  /    |\_ /|      / /   / \   \_\
       /  /  |\/ _ '_|\    / /   /   \    \
      |  /   |/  0 \0\ \  / |    |    \    \
      |    |\|      \_\_ /  /    |     \    \
      |  | |/    \.\ o\o)  /      \     |    \
      \    |     /\`v-v  /         |    |     \
       | \/    /_| \_|  /          |    | \    \
       | |    /__/_     /   _____  |    |  \    \
       \|    [__]  \_/  |_________  \   |   \    ()
        /    [___] (    \         \  |\ |   |   //
       |    [___]                  |\| \|   /  |/
      /|    [____]                  \  |/\ / / ||
    (  \   [____ /     ) _\      \  \    \| | ||
      \  \  [_____|    / /     __/    \   / / //
      |   \ [_____/   / /        \    |   \/ //
      |   /  '----|   /=\____   _/    |   / //
   __ /  /        |  /   ___/  _/\    \  | ||
  (/-(/-\)       /   \  (/\/\)/  |    /  | /
                (/\/\)           /   /   //
                       _________/   /    /
                      \____________/    
                   buGs geT EaTeNN.
*/

/*******************************
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
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n = 2e5 + 5;
vvi adj(n);
vi ind(n);

vi BFS()//returns the BFS ordering
{
    vi ordering;
    queue<int>q;
    vb vis(n + 1);
    vis[1] = 1;
    q.push(1);
 
    while (!q.empty()){
        int u = q.front();
        ordering.pb(u);
        q.pop();
        for (int v:adj[u]){
            if (!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return ordering;
}
bool comp(int i,int j)
{
    return ind[i] < ind[j];
}

int main(){
    //freopen("in.txt","r",stdin);;
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0;i<n - 1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v),adj[v].pb(u);
    }
    vi a(n);
    for (int i = 0;i<n;i++){
        cin>>a[i];
        ind[a[i]] = i;//this is because a[i] occurs at position i
    }
    for (int i = 1;i<=n;i++)
        sort(adj[i].begin(),adj[i].end(),comp);
 
    if (BFS() == a)cout <<"YES" << flush;
    else cout <<"No" << flush;
    return 0;
}
