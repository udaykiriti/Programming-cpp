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
	string s; cin >> s;
	int cnt = 0;
	for(idx i = 0; i < s.size(); ++i){
		if(s[i] == 'a') ++cnt;
	}
	if(cnt > (s.size() / 2)) cout << s.size() << ln;
	else cout << cnt + (cnt - 1) << ln;
	return 0;
}