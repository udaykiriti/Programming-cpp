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

// Macros
#define ll long long
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define all(x) x.begin(), x.end()
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define TESTS \
  int t;      \
  cin >> t;   \
  while (t--)

// Constants
const ll INF = 2e18 + 99;

int main()
{
  FAST_IO;
  TESTS
  {
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

    // Convert all elements to absolute values
    for (int &x : arr)
      x = abs(x);

    if (neg_count % 2 == 0)
    {
      cout << ans << endl;
    }
    else
    {
      int min_val = *min_element(all(arr));
      cout << ans - 2 * min_val << endl;
    }
  }

  return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl "\n"
// #define debug(n) cout<<(n)<<endl;
// #define pb push_back
// const ll INF = 2e18 + 99;

// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);

//   int t;
//   cin>>t;
//   while(t--){
//     int n;
//     cin>>n;
//     vector<int> arr(n), prefix(n, 0);
//     ll ans = 0, count = 0;
//     for(int i = 0; i < n; i++){
//       cin>>arr[i];
//       ans += abs(arr[i]);
//       if(arr[i] < 0) count++;
//     }
//     for(int i= 0;i < n; i++){
//       if(arr[i] < 0){
//         arr[i] = abs(arr[i]);
//       }
//     }
//     if(!(count % 2)){
//       cout<<ans<<endl;
//       continue;
//     }
//     int mini = *min_element(arr.begin(), arr.end());
//     cout<<ans-(2*mini)<<endl;

//   }

// }
