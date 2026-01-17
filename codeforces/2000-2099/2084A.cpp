#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
  int n; cin >> n;
	if (n & 1) {
		cout << n << ' ';
		for (int i = 1; i < n; ++i) {
	    	cout << i << " \n"[i == n - 1];
		}
	} else {
		cout << "-1"<<endl;
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
	int t(1),tcase(0); cin >> t;
	while (++tcase,t--) solve();
	return 0;
}
