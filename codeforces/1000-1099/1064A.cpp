#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int a, b, c, count = 0; cin >> a >> b >> c;
	if(a + b <= c){
		count += (c - (a + b)) + 1;
		a += count;
	}
	if(b + c <= a){
		count += (a - (b + c)) + 1;
		b += (a - (b + c)) + 1;
	}
	if(c + a <= b){
		count += (b - (c + a)) + 1;
		c += (b - (c + a)) + 1;
	}
	cout << count << endl;
	return 0;
}