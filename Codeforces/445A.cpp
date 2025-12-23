/******************************
 *    author:  uday           *
 *    created: 24 16:10:10    *
 ******************************/

// g++ -std=c++17 new.cpp -o new
// ./new
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

#define MAX 102
char s[MAX][MAX];
char c[MAX][MAX];
int n,m;

void solve(){
   //solution here.........
   while(cin>>n>>m){
    memset(s,0,sizeof(c));
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j] == '-') c[i][j] = '-';
            else{
                if((i+j)%2 == 0) c[i][j] = 'W';
                else c[i][j] ='B';
            }
        } 
    }
    for(int i=0;i<n;i++) cout<<c[i]<<endl;
   }
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}