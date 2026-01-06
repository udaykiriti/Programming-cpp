#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 /*
 we have to figure out f[i]=0;
 what about more than one element 0
 ok we can distribute them 
 [i][max][left_elements](left elements > maxfreq of removed sets)
 what if f[i]<max
 1 line and other dont transition
 what can we romove??
 what will it look like 
100 max values
5000*100*log(5000)????
aint no way hose
let me try skully
7.7 e7
 */
// --- your modnum template (unchanged) ---
template<long long mod>
struct modnum {
    static constexpr bool is_big_mod = mod > numeric_limits<int>::max();

    using S = conditional_t<is_big_mod, long long, int>;
    using L = conditional_t<is_big_mod, long long, long long>;

    S x;

    modnum() : x(0) {}
    modnum(long long _x) {
        _x %= static_cast<long long>(mod);
        if (_x < 0) { _x += mod; }
        x = static_cast<S>(_x);
    }

    modnum pow(long long n) const {
        modnum res = 1;
        modnum cur = *this;
        while (n > 0) {
            if (n & 1) res *= cur;
            cur *= cur;
            n /= 2;
        }
        return res;
    }
    modnum inv() const { return (*this).pow(mod-2); }

    modnum& operator+=(const modnum& a){
        x += a.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    modnum& operator-=(const modnum& a){
        if (x < a.x) x += mod;
        x -= a.x;
        return *this;
    }
    modnum& operator*=(const modnum& a){
        x = static_cast<S>( static_cast<L>(x) * a.x % mod );
        return *this;
    }
    modnum& operator/=(const modnum& a){ return *this *= a.inv(); }

    friend modnum operator+(const modnum& a, const modnum& b){ return modnum(a) += b; }
    friend modnum operator-(const modnum& a, const modnum& b){ return modnum(a) -= b; }
    friend modnum operator*(const modnum& a, const modnum& b){ return modnum(a) *= b; }
    friend modnum operator/(const modnum& a, const modnum& b){ return modnum(a) /= b; }

    friend bool operator==(const modnum& a, const modnum& b){ return a.x == b.x; }
    friend bool operator!=(const modnum& a, const modnum& b){ return a.x != b.x; }
    friend bool operator<(const modnum& a, const modnum& b){ return a.x < b.x; }

    friend ostream& operator<<(ostream& os, const modnum& a){ os << a.x; return os; }
    friend istream& operator>>(istream& is, modnum& a) { long long x; is >> x; a = modnum(x); return is; }
};

const long long MOD = 998244353;
using mint = modnum<MOD>;

template<long long mod>
struct Factorials {
    using mint_t = modnum<mod>;
    vector<mint_t> fact, invfact;
    Factorials() = default;
    void init(int n) {
        fact.assign(n+1, mint_t(1));
        invfact.assign(n+1, mint_t(1));
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * mint_t(i); 

        invfact[n] = fact[n].inv();
        for (int i = n; i > 0; --i)
            invfact[i-1] = invfact[i] * mint_t(i); 
    }
    mint_t nCr(int n, int r) const {
        if (r < 0 || r > n) return mint_t(0);
        return fact[n] * invfact[r] * invfact[n-r];
    }
    mint_t nCr_lucas(long long n, long long r) const {
        if (r < 0 || r > n) return mint_t(0);
        mint_t res = 1;
        while (n > 0 || r > 0) {
            int ni = static_cast<int>(n % mod);
            int ri = static_cast<int>(r % mod);
            if (ri > ni) return mint_t(0);
            res *= nCr(ni, ri); 
            n /= mod;
            r /= mod;
        }
        return res;
    }
};



Factorials<MOD> F;
void Solve() 
{
    ll n;
    cin>>n;
    vector<ll>v(n);

    for(auto &it:v)cin>>it;
    vector<ll>freq(n+1,0),f(n+1,0);

    for(ll i=0;i<n;i++){
        freq[v[i]]++;
    }
    for(ll i=0;i<=n;i++){
        if(freq[i] > 0)f[freq[i]]++;
    }

    ll m=0;  

    // for(auto it:freq)cout<<it<<" ";
    // cout<<endl;
    // for(auto it:f)cout<<it<<" ";
    // cout<<endl;

    for(auto it:f)if(it>0)m++;

    vector<vector<ll>>dp(m+1,vector<ll>(n+1,0)),ndp(m+1,vector<ll>(n+1,0));
    dp[0][n]=1;

    ll z = 0;
    for(ll i = 1; i<=n ;i++){
        if(f[i] > 0){

           z++;
           ndp=dp;
           ll c = (mint(i).pow(f[i])).x;

            for(ll i1=0;i1<=z;i1++){
                for(ll i2=0;i2<=n;i2++){
                    ndp[i1][i2] = (dp[i1][i2]*c) % MOD;
                    if(i1 >= 1)dp[i1][i2] +=  dp[i1-1][i2];
                               dp[i1][i2] %= MOD;
                 }
            }
            
            for(ll i1 = n; i1 >= i ;i1--){
               for(ll i2 = 1 ; i2 <= f[i] ; i2++){
                mint k = F.nCr(f[i] , i2) * mint(i).pow(f[i] - i2);
                 if(i1 + (i2 * i) <= n){
                    ndp[z][i1] += dp[z][i1 + (i2 * i)] * k.x ;
                    ndp[z][i1] %= MOD;
                 }
               }
            }    
            
            swap(dp,ndp);
        }
    }
    mint ans=0;

    for(ll i=0;i<=m;i++){
        for(ll j=0;j<=n;j++)ans+=dp[i][j];
    }
    
    cout<<ans<<endl;
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;

    
    const int MAXN = 5000;
    F.init(MAXN);

    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(ll i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
/*
    Solutions are simple.
 
    Proofs are simple.
 
    Implementations are simple.

    Find invariants 

    Try to reduce to mathematical experssion

    Check for upper/lower bounds

    DP in a way to relax the constraint ,Store minimum required information

    Dont stick to a idea for too long

    Dont make elaborate plans and big assumption without having a bare minimum idea of proof

    Try working from backwards or endcase

    Reverse the problem dont think what to get think what not to get

    If ur clueless after first 30 mins give up , if u dont have a solution within 1.5 hrs give up.
*/