#include<bits/stdc++.h>
#define bug(x)				  cout<<"  [ "#x<<" = "<<x<<" ]"<<endl;

using namespace std;
void solve()
{
	string s; cin>>s;
	int zero=0,one=0;
	for(auto i:s)
	{
		if(i=='0')
			zero++;
		else
			one++;
	}
	int ans=min(zero,one);
	if(ans%2)
		cout<<"DA"<<endl;
	else
		cout<<"NET"<<endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
	int t=1;	cin>>t;
	while(t--) solve();
  return 0;
}
