#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;
    while(t--){
        ll n, moves; cin >> n >> moves;
        ll ans;
        if(n % 2 == 0){
            if(moves % 4 == 0) ans = n;
            else if(moves % 4 == 1) ans = n - moves;
            else if(moves % 4 == 2) ans = n + 1;
            else ans = n + moves + 1;
        }
        else{
            if(moves % 4 == 0) ans = n;
            else if(moves % 4 == 1) ans = n + moves;
            else if(moves % 4 == 2) ans = n - 1;
            else ans = n - moves - 1;
        }
        cout << ans << "\n";
    }
}
