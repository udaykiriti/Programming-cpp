#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define int long long

template <class T>
void print_v(vector<T> &v) { 
    cout << "{";
    for (auto x : v) cout << x << ",";
    cout << "\b}";
}

void solver() {
    int n,k1,k2;
    cin >> n >> k1 >> k2;
    int k = k1+k2;
    
    vi a(n),b(n);

    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    multiset<int> s;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int p = abs(a[i]-b[i]);
        if(p != 0) s.insert(p);
        cnt += p;
    }
    if(k >= cnt){
        if(k%2 == cnt % 2) cout <<"0\n";
        else cout <<"1\n";
        return;
    }
    while( !s.empty() && k>0){
        auto z = s.rbegin();
        int val = *z;
        auto it = s.find(val);
        s.erase(it);
        val--;
        k--;
        if(val > 1) s.insert(val);
    }
    int ans=0;
    for(int t: s){
        ans += t*t;
    }
    cout << ans << "\n";
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solver();
    return 0;
}