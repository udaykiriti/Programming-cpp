#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)

int solve(int n){
  if (n % 7 == 0) return n;
  FOR(i, 0, 10){
    int x = ((n / 10) * 10) + i;
    if (x % 7 == 0) return x;
  }return -1;
}

int main(int argc , char *argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;cin >> t;
  while (t--){
    int n; cin >> n;
    cout << solve(n) << endl;
  } return 0;
}
