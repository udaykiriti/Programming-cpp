#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// Type aliases for convenience
using lli = long long int;
using uInt = unsigned int;
using ulli = unsigned long long int;
using vi = vector<int>;
using vii = vector<lli>;
using vc = vector<char>;
using udouble = long double;
using vd = vector<double>;
using vs = vector<string>;

template <typename T>
using vv = vector<vector<T>>; // 2D array
template <typename T>
using pq = priority_queue<T>; // max-heap priority queue
template <typename T>
using pq_ = priority_queue<T, vector<T>, greater<T>>; // min-heap priority queue
template <typename T1, typename T2>
using vp = vector<pair<T1, T2>>; // vector of pairs

// Miscellaneous constants and macros
#define ln "\n"                               // line break, no flush
#define _flush endl                           // flush output
#define stop_sync ios::sync_with_stdio(false) // Disable sync with C-style IO for faster input/output
#define untie_ios cin.tie(nullptr)            // Untie cin from cout to speed up input
#define pb push_back                          // Push to vector
#define ppb pop_back                          // Pop from vector
#define mp make_pair                          // Make a pair
#define Fi(p) get<0>(p)                       // First element of pair
#define Sc(p) get<1>(p)                       // Second element of pair
#define sz(x) int((x).size())                 // Size of container
#define All(x) (x).begin(), (x).end()         // All elements of container
#define scanv(x)    \
  for (auto &i : x) \
  cin >> i                                        // Read entire vector
#define bin_sc(a, x) binary_search(All(a), x)     // Binary search (returns bool)
#define lbd(a, x) lower_bound(All(a), x)          // Lower bound iterator
#define ubd(a, x) upper_bound(All(a), x)          // Upper bound iterator
#define eq_seg(a, x) equal_range(All(a), x)       // Returns pair of iterators (lower bound, upper bound)
#define minE(a) (*min_element(All(a)))            // Minimum element
#define maxE(a) (*max_element(All(a)))            // Maximum element
#define FIXED(x) cout << fixed << setprecision(x) // Set fixed decimal precision
#define mem(a, v) memset(a, v, sizeof a)          // Memory set for array
#define filla(a, n, v) fill(a, a + n, v)          // Fill array with value
#define fillv(a, v) fill(All(a), v)               // Fill vector with value
#define _fillv(a, n, v) fill_n(a.begin(), n, v)   // Fill first n elements of vector with value
#define glue(x, y) x##y                           // Concatenate two tokens
#define msg(x) cout << (#x) << ln                 // Print variable name
#define bug(x) cout << (#x) << ": " << (x) << ln  // Debug variable
#define printv(v)     \
  for (auto i : v)    \
    cout << i << ' '; \
  cout << ln // Print vector
#define printvv(v)      \
  for (auto i : v)      \
  {                     \
    for (auto j : i)    \
      cout << j << ' '; \
    cout << ln;         \
  } // Print 2D vector
#define printm(m)  \
  for (auto i : m) \
  cout << Fi(i) << " -> " << Sc(i) << ln // Print map
#define prints(s)     \
  for (auto i : s)    \
    cout << i << ' '; \
  cout << ln                                                            // Print string
#define uceil(a, b) ((a + b - 1) / (b))                                 // Ceiling division
#define unq_v(a) a.resize(distance(a.begin(), unique(All(a))))          // Remove duplicates from vector
#define mk_upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper) // Convert string to uppercase
#define mk_lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower) // Convert string to lowercase
#define valid(nx, ny) (nx >= 1 && nx <= row && ny >= 1 && ny <= col)    // Check if coordinates are valid
#define dbug(args...)          \
  {                            \
    string s = #args;          \
    replace(All(s), ',', ' '); \
    stringstream s2;           \
    s2 << s;                   \
    vs ss;                     \
    while (s2)                 \
    {                          \
      string now;              \
      s2 >> now;               \
      ss.pb(now);              \
    }                          \
    debug(ss, args);           \
  } // Debugging macro

// Directional arrays (used for 8-directional moves)
vector<int> dx = {1, -1, 0, 0, 1, -1, -1, 1}; // Directions for x-axis (4 cardinal + 4 diagonal)
vector<int> dy = {0, 0, 1, -1, 1, 1, -1, -1}; // Directions for y-axis (4 cardinal + 4 diagonal)

// Mathematical constants
const string yms[]{"YES", "Yes", "yes"};
const string nms[]{"NO", "No", "no"};
const double PI = acos(-1.0L); // Pi constant

// Modulo and infinity constants
struct
{
  const int i = (1e9) + 7;
  const lli l = (lli)(1e9) + 7ll;
} MOD;
struct
{
  const int i = INT_MAX;
  const lli l = LLONG_MAX;
} inf;

// Some utility functions
bool isUp(char ch)
{
  locale loc;
  return isupper(ch, loc);
} // Check if character is uppercase
int ffs(int x) { return __builtin_ffs(x); }          // First set bit from the right (1-based index)
int ffs(lli x) { return __builtin_ffsll(x); }        // First set bit for long long
int clz(uInt x) { return __builtin_clz(x); }         // Leading zeros (count from the left)
int clz(ulli x) { return __builtin_clzll(x); }       // Leading zeros for unsigned long long
int ctz(uInt x) { return __builtin_ctz(x); }         // Trailing zeros (count from the right)
int ctz(ulli x) { return __builtin_ctzll(x); }       // Trailing zeros for unsigned long long
int cto(uInt x) { return __builtin_popcount(x); }    // Count of 1 bits
int cto(ulli x) { return __builtin_popcountll(x); }  // Count of 1 bits for unsigned long long
int parity(uInt x) { return __builtin_parity(x); }   // Parity (odd or even number of 1 bits)
int parity(ulli x) { return __builtin_parityll(x); } // Parity for unsigned long long
auto pow2(uInt x) { return (1u) << x; }              // Power of 2 (unsigned int)
auto pow2(ulli x) { return (1ull) << x; }            // Power of 2 (unsigned long long)
lli binpow(lli a, lli b)
{
  lli ans = 1ll;
  while (b > 0)
  {
    if (b & 1)
      ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
} // Binary exponentiation
lli binpow(lli a, lli b, lli m)
{
  a %= m;
  lli ans = 1ll;
  while (b > 0)
  {
    if (b & 1)
      ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans;
} // Binary exponentiation with modulo
lli NcR(lli n, lli r)
{
  lli x = 1ll, y = 1ll;
  if (n - r < r)
    r = n - r;
  while (r)
  {
    x *= n;
    y *= r;
    lli cm = __gcd(x, y);
    x /= cm;
    y /= cm;
    --n;
    --r;
  }
  return x;
} // Combination (nCr)
lli NpR(lli n, lli r)
{
  lli x = 1ll;
  while (r)
  {
    x *= n;
    --n;
    --r;
  }
  return x;
} // Permutation (nPr)

// Template function to calculate the sum of the first n numbers
template <typename type>
type Nsum(type n) { return (n * (n + 1)) / (type)2; }

// Round up function for integer division
template <typename type>
type Round(type a, type b)
{
  if (a < b)
    return 1;
  if (a % b)
    return 1 + a / b;
  return a / b;
}

template <typename T, typename... param>
void debug(vs ss, T a, param... args)
{
  cout << ss.front() << " = " << a << '\n';
  ss.erase(ss.begin());
  debug(ss, args...); // Debug function for variable args
}

// Main function
int main(void)
{
  stop_sync; // Disable synchronization for fast IO
  untie_ios; // Untie cin from cout for better performance

#ifndef ONLINE_JUDGE
             // freopen("generator.txt", "r", stdin);
  freopen("input.txt", "r", stdin);   // Open input file for testing
  freopen("output.txt", "w", stdout); // Open output file for testing
  freopen("error.txt", "w", stderr);  // Open error file for testing
#endif

  int t(1), tcase(0);
  cin >> t; // Read number of test cases
  while (++tcase, t--)
  {
    // cout << "--------Case #" << tcase << ": --------\n";
    string s;
    string ans;
    for (int i = 0; i < 8; ++i)
    {
      cin >> s; // Read each row of the board
      for (int j = 0; j < 8; ++j)
      {
        if (s[j] != '.')
          ans.pb(s[j]); // Collect non-empty cells
      }
    }
    cout << ans << ln; // Output the result
  }
  return 0;
}
