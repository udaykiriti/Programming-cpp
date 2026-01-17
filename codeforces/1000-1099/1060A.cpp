#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define vi vector<int>
#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int n, cnt = 0;
	string s; cin>>n>>s;
	for(int i = 0; i < n; ++i)
		if(s[i] == '8') ++cnt;
	n /= 11;
	if(cnt >= n) cout << n << endl;
    else cout << cnt << endl;
	return 0;
}