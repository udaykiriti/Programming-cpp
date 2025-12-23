#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define pb      push_back
#define sz(x)   int((x).size())
#define All(x)  (x).begin(), (x).end()
using i64 =     long long;

void solve()
{
  i64 n; cin >> n;
  map<i64, i64> freq;
  i64 maxFreq = 0;
  for (i64 i = 0; i < n; i++)
  {
    i64 a; cin >> a;
    freq[a]++;
    maxFreq = max(maxFreq, freq[a]);
  }

  i64 distinct = freq.size();
  i64 result = 0;
  if (distinct == maxFreq) result = distinct - 1;
  else result = min(distinct, maxFreq);
  cout << result << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
}