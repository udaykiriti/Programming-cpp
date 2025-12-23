#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef size_t idx;
#define vi vector<int>
#define pb(n) push_back(n)
#define ln "\n"
#define sp ends
#define newline cout << ln
#define fastios ios_base::sync_with_stdio(false); cin.tie(0)

int main(){
	int t, n;
	string s; cin >> t;
	while(t--){
		cin >> n >> s;
		sort(s.begin(), s.end());
		cout << s << ln;
	}
	return 0;
}