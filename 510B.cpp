/******************************
 *    author:  uday           *
 *    created: 26 23:31:26    *
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

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n,m;
vector<vector<bool>> vis;
vector<vector<char>> tab;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool dfs(int i,int j, int pi,int pj){
    vis[i][j] = true;
    for(int p = 0; p < 4; p++){
        int di = i + dx[p];
        int dj = j + dy[p];

        if(di < 0 || di >= n || dj < 0 || dj >= m){
            continue;
        }
        if(tab[di][dj] != tab[i][j]){
            continue;
        }
        if(vis[di][dj] && (di != pi || dj != pj)){
            return true;
        }
        if(!vis[di][dj] && dfs(di,dj,i,j)){
            return true;
        }
    }
    return false;
}


bool ISCYCLE(){
    //memset(vis,false,sizeof(vis));
    vis.assign(n,vector<bool>(m,false));
    debug(vis);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                if(dfs(i,j,-1,-1)){
                    return true;
                }
            }
        }
    }
    return false;
}

void solve(){
   //solution here.........
   cin>>n>>m;
   tab.assign(n,vector<char>(m));
   for(int i = 0;i < n;i++){
    for(int j=0;j<m;j++){
        cin>>tab[i][j];
    }
   }
   cout << (ISCYCLE() ? "Yes" : "No");
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}