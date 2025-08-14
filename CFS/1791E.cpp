/*
    Codeforces Problem 1791E - Negatives and Positives
    Problem Link: https://codeforces.com/problemset/problem/1791/E

    Given an array, you can perform the following operation any number of times:
    - Choose two adjacent elements and multiply both of them by -1.

    This operation changes the sign of both selected elements.

    The goal is to maximize the **sum of absolute values** of all array elements
    after performing any number of operations.

    Approach:
    - After making all elements positive, the sum of their absolute values is maximized.
    - But, if the number of negative elements is **odd**, one negative will remain
      (as each operation affects two elements).
    - Thus, subtract twice the smallest absolute value from the sum to simulate
      the optimal result in that case.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()
const ll INF = 2e18 + 99;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n; cin >> n;
    vector<int> arr(n);
    ll ans = 0;
    int neg_count = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      ans += abs(arr[i]);
      if (arr[i] < 0)
        neg_count++;
    }
    for (int &x : arr)
      x = abs(x);

    if (neg_count % 2 == 0){
      cout << ans << endl;
    }
    else{
      int min_val = *min_element(all(arr));
      cout << ans - 2 * min_val << endl;
    }
  }
  return 0;
}