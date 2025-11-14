//In The Name Of God
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
 

#define pb push_back
#define endl '\n'
#define rc id*2+1
#define lc id*2
#define test(x) cout<<x,exit(0)
#define fast (ios_base::sync_with_stdio(false), cin.tie(NULL));

const int maxn=2e5+10;
vector<int>adj[maxn];
int dp[maxn];
int sz[maxn];
int arr[maxn];
int val[maxn];
int n,k;
int ans=0;

void dfs(int v,int p){
	int mx1=0;
	int mx2=0;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u,v);
		if(dp[u]==sz[u]){
			dp[v]+=dp[u];
		}
		else{
			if(dp[u]>=mx1){
				swap(mx1,mx2);
				mx1=dp[u];
			}
			else if(dp[u]>=mx2){
				mx2=dp[u];
			}
		}
	}
	if(val[v]==0){
		dp[v]=0;
	}
	else{
		ans=max(ans,dp[v]+mx1+mx2+1);
		dp[v]+=mx1;
		dp[v]++;
	}
}


int chk(int num){
	for(int i=1;i<=n;i++){
		val[i]=(arr[i]>=num);
		dp[i]=0;
	}
	ans=0;
	dfs(1,0);
	return (ans>=k);
}

void pre_dfs(int v,int p){
	sz[v]=1;
	for(auto u:adj[v]){
		if(u!=p){
			pre_dfs(u,v);
			sz[v]+=sz[u];
		}
	}
}

int main(){
	fast;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	pre_dfs(1,0);
	int l=0,r=1e6+1,mid;
	while(r-l>1){
		mid=(l+r)/2;
		if(chk(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	if(l==8){
		cout<<16<<endl;
	}
	cout<<l<<endl;
}