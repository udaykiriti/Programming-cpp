#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(NULL);
	int n, ai; cin >> n;
	int arr[101] = {};
	for(int i = 0; i < n; ++i){
		cin >> ai;
		++arr[ai];
	}
	int mx = *max_element(arr, arr + 101);
	cout << mx << endl;
	return 0;
}