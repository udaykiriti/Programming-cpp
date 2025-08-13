#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef size_t idx;
#define vi vector<int>
#define pb(n) push_back(n)
#define endl "\n"
const int MOD = 1000000007;

lli trial(lli n){
	for(lli d = 3; d * d <= n; d += 2){
		if(n == 1) break;
		while(!(n % d)){
			return d;
		}
	}
	return n;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	lli n; cin >> n;
	if(!(n % 2)) cout << n / 2 << endl;
	else{
		n -= trial(n);
		cout << (n / 2) + 1 << endl;
	}
	return 0;
}