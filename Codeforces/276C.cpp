#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, q; cin >> n >> q;
  vector<long long> a(n), freq(n + 1, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    freq[l - 1]++;
    freq[r]--;
  }
  for (int i = 1; i < n; ++i)
    freq[i] += freq[i - 1];
  freq.pop_back();
  sort(a.begin(), a.end());
  sort(freq.begin(), freq.end());
  long long result = 0;
  for (int i = 0; i < n; ++i)
    result += a[i] * freq[i];
  cout << result << endl;
  return 0;
}
