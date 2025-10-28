#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve(){
    int n;
    cin >> n;
    vll vec(n);
    int e(0),o(0);
    for(auto &x : vec){
        cin>>x;
        (x % 2 == 0 ? e : o)++;
    }
    if(e  and o )
        sort(vec.begin(),vec.end());
        
    for (int i = 0; i < n; i++) {
    cout << vec[i];
    if (i != n - 1)  cout << " ";
    else  cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; 
    cin >> t;
    while(t--) solve();

}