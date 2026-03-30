#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

const int MAX = 100005;
long long cnt[MAX];
long long dp[MAX];

void _solve(){
	int n;
	cin >> n;

	int maxi{0};

	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		cnt[x]++;
		maxi = max(maxi,x);
	}

	dp[0] = 0;
	dp[1] = cnt[1];

	for(int i = 2; i<=maxi ; i++){
		dp[i] = max(dp[i-1],dp[i-2] + i * cnt[i]);
	}
	
	cout << dp[maxi] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t{1};
	//cin >> t;
	while(t--)
		_solve();
}