#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> dp;      // dp[v][c] = ways to color subtree v with color c
vector<vector<int>> adj;
vector<int> color;           // precolored: -1 = free, else 0/1/2

void solve(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,pair<int,int>> u;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            u[a]={i,j};
        }
    }
    vector<vector<int>> newmatrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>newmatrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int row=u[newmatrix[i][0]].first;
        for(int j=1;j<m;j++){
            if(u[newmatrix[i][j]].first!=row){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    for(int j=0;j<m;j++){
        int col=u[newmatrix[0][j]].second;
        for(int i=1;i<n;i++){
            if(u[newmatrix[i][j]].second!=col){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

