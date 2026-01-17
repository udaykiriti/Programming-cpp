/*
    Codeforces Problem 9A - Die Roll

    Yakko and Wakko roll a standard 6-sided die and get values Y and W.
    Dot wants to know the probability that she can win by rolling a value
    that is at least as high as the maximum of Y and W. If she ties, she wins.

    The total number of outcomes on a 6-sided die is 6.
    The number of favorable outcomes is (6 - max(Y, W) + 1).
    The output is the simplified probability of winning as a fraction.

    Sample Input:
    4 2

    Sample Output:
    1/2

    Explanation:
    The maximum of 4 and 2 is 4.
    Dot can win by rolling 4, 5, or 6 — 3 favorable outcomes out of 6.
    Probability = 3/6 = 1/2.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout << (n) << endl;
#define PRINT(x) cout << (x) << endl;
const ll INF = 2e18 + 99;

void FastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
}

int main()
{
  FastIO();
  int a, b; cin >> a >> b;
  if (max(a, b) == 1)
    PRINT("1/1")
  else if (max(a, b) == 2)
    PRINT("5/6")
  else if (max(a, b) == 3)
    PRINT("2/3")
  else if (max(a, b) == 4)
    PRINT("1/2")
  else if (max(a, b) == 5)
    PRINT("1/3")
  else
    PRINT("1/6")
}