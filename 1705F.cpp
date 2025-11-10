#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int n,p;
int ans[1005],id[1005];
bool f[1005];
mt19937 rnd(time(0));
int query(int l,int r)
{
	for(int i=1;i<=n;i++){
		f[i]=0;
    }
	for(int i=l;i<=r;i++){
		f[id[i]]=1;
    }
	for(int i=1;i<=n;i++){
		if(f[i])
			cout<<"T";
		else
			cout<<"F";
    }
	cout<<"\n";
	cout.flush();
	int x;
	cin>>x;
	if(x==-1){
		exit(1);
    }
	if(l==1&&r==n){
		p=x;
    }
	x=n-x;
	if(!x){
		exit(0);
    }
	return ((r-l+1)+p-x)>>1;
}
void solve(int l,int r,int num)
{
	if(num==r-l+1)
	{
		for(int i=l;i<=r;i++)
			ans[id[i]]=1;
		return;
	}
	if(!num)
		return;
	int mid=l+r>>1;
	int x=query(l,mid);
	solve(l,mid,x);
	solve(mid+1,r,num-x);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		id[i]=i;
	for(int i=1;i<=n;i++)
		swap(id[i],id[rnd()%i+1]);
	solve(1,n,query(1,n));
	for(int i=1;i<=n;i++)
		if(ans[i])
			cout<<"T";
		else
			cout<<"F";
	cout<<"\n";
	cout.flush();
}