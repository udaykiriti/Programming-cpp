/******************************
 *    author:  -----          *
 *    created: 19 16:10:03    *
 ******************************/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int  a, b, n, s;
	cin >> a >> b>> n >> s;	
	int k = s/n;
	if( s/n > a) k = a;
	if(s - (k * n) <= b) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int t(1),tcase(0); cin >> t;
	while(++tcase,t--) solve();
	return 0;
}