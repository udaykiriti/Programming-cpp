#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) c[i] = a[i] - b[i];
    sort(c.begin(), c.end());
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int x = upper_bound(c.begin() + i + 1, c.end(), -c[i]) - c.begin();
        res += (n - x);
    }
    cout << res << '\n';
    return 0;
}