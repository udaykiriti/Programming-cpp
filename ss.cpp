#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

void _solve(){
	int n,cnt{0},maxi{0};
	cin >> n;
	for(int i = 0 ; i < n ;i++){
		int ele ;
		cin >> ele;
		if(0 == ele){
			cnt++;
			maxi = max(maxi,cnt);
		}else{
			cnt = 0;
		}
	}
	cout << maxi << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--)
		_solve();
}