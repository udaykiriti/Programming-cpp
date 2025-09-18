/* Problem: I Hate 1111
You are given an integer `n`. You need to determine if it is possible to represent `n` as the sum of some number of 11s and 111s.

Input:
The first line contains a single integer `t` (1 ≤ t ≤ 100) — the number of test cases.
Each of the next `t` lines contains a single integer `n` (1 ≤ n ≤ 10^9).

Output:
For each test case, print "YES" if it is possible to represent `n` as the sum of some number of 11s and 111s, otherwise print "NO".

Example:
Input:
3
33
144
69
Output:
YES
YES
NO
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    bool ok = false;
    while (n > 0) {
      if (n % 11 == 0 || n % 111 == 0) {
        ok = true;
        break;
      } else {
        n -= 111;
      }
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
