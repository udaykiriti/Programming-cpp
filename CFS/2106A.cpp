#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long t; cin >> t;
    while(t--){
        long n; cin >> n;
        string s; cin >> s;
        long cnt(0);
        for(size_t p = 0; p < s.size(); p++){
          cnt += (n - 2) * (s[p] == '1') + 1;
        }
        cout<<cnt<<endl;
    }
}
