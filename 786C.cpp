#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const ll maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll sq = 500;

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define print(x) for (auto &a : x) {cout << a << ' ';} cout << endl

ll n;
ll a[maxn];

ll get(ll x) {
    unordered_set<ll> st;
    ll c = 0, ans = 1;
    for (ll i = 1; i <= n; i++) {
        if (!st.count(a[i])) {
            if (c == x) {
                ans++;
                c = 0;
                st.clear();
            }
            c++;
            st.insert(a[i]);
        }
    }

    return ans;
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    for (ll k = 1; k <= min(n, sq); k++)
        cout << get(k) << ' ';

    for (ll k = sq + 1; k <= n;) {
        ll x = get(k);
        ll l = k, r = n + 1;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (get(m) == x) l = m;
            else r = m;
        }
        for (ll j = k; j < r; j++) {
            cout << x << ' ';
            k++;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tst = 1;
    // cin >> tst;
    while (tst--)
        solve();

    return 0;
}