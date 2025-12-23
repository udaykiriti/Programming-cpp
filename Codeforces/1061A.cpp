#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef size_t idx;
#define vi vector<int>
#define pb(n) push_back(n)
#define endl "\n"
#define sp ends

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int n, s; cin >> n >> s;
	int coin = n, cnt = 0;
	while(1){
		if(s == 0) break;
		while(s >= coin){
			++cnt;
			s -= coin;
		}
		--coin;
	}
	cout << cnt << endl;
	return 0;
}