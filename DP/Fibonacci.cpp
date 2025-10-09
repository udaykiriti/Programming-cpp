#include <bits/stdc++.h>
using namespace std;

int f(int n , vector<int> &dp){
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1 , dp) + f(n-2 , dp);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n; cin>>n;
    vector<int> dp(n+1,-1);
    cout<< f(n,dp)<<endl;
    return 0;
}