#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL MOD = 1e9 + 7;
const int maxn = 100005;
#define endl '\n'

int mu[maxn];
bool not_prime[maxn];
vector<int> prime;

void get_mu(int len) {
    mu[1] = not_prime[1] = 1;
    for (int i = 2;i <= len;++i) {
        if (!not_prime[i]) { prime.push_back(i); mu[i] = -1; }
        for (auto j : prime) {
            int mid = i * j;
            if (mid > len) break;
            not_prime[mid] = 1;
            if (i % j == 0) { mu[mid] = 0; break; }
            mu[mid] = -mu[i];
        }
    }
}

int f[maxn], g[maxn];

int main() {
    get_mu(100000);
    int n;cin >> n;
    for (int x = 1;x <= n;++x) {
        int c = 1;
        for (c = 1;c * c < x;++c) {
            if (x % c == 0) {
                f[x] += mu[c] * (x / c - 1);
                f[x] += mu[x / c] * (c - 1);
            }
        }
        if (c * c == x) f[x] += mu[c] * (x / c - 1);
    }
    LL ans = 0;
    for (int x = 1;x < n;++x) {
        LL temp = 0;
        for (int d = 1;d <= (n - 1) / x;++d)
            temp = (temp + ((n - x * d) / __gcd(n - x * d, d) * d)) % MOD;
        ans = (ans + temp * f[x] % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}