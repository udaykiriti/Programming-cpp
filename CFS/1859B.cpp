/*
Problem Description:

Artem suggested a game to the girl Olya. There is a list of n arrays, where the i-th array contains mi (mi ≥ 2) positive integers ai,1, ai,2, ..., ai,mi.

Olya can move at most one (possibly 0) integer from each array to another array. Note that integers can be moved from one array only once, but integers can be added to one array multiple times, and all the movements are done at the same time.

The beauty of the list of arrays is defined as the sum of the minimum values of each array:
    Beauty = ∑(min(a_{i,1}, a_{i,2}, ..., a_{i,mi}))

In other words, for each array, we find the minimum value in it and then sum up these minimum values.

The goal of the game is to maximize the beauty of the list of arrays. Help Olya win this challenging game!

Input:
Each test case consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 25,000) — the number of test cases. The description of the test cases follows.

For each test case:
    - The first line contains a single integer n (1 ≤ n ≤ 25,000) — the number of arrays in the list.
    - This is followed by descriptions of the arrays:
        - The first line contains a single integer mi (2 ≤ mi ≤ 50,000) — the number of elements in the i-th array.
        - The next line contains mi integers ai,1, ai,2, ..., ai,mi (1 ≤ ai,j ≤ 10^9) — the elements of the i-th array.

It is guaranteed that the sum of mi over all test cases does not exceed 50,000.

Output:
For each test case, output a single line containing a single integer — the maximum beauty of the list of arrays that Olya can achieve.

Example Input:
3
2
2
1 2
2
4 3
1
3
100 1 6
3
4
1001 7 1007 5
3
8 11 6
2
2 9

Example Output:
5
1
19

Note:
In the first test case, we can move the integer 3 from the second array to the first array. Then the beauty is min(1, 2, 3) + min(4) = 5. It can be shown that this is the maximum possible beauty.
In the second test case, there is only one array, so regardless of the movements, the beauty will be min(100, 1, 6) = 1.
*/
/*
Problem Description:
You are given t test cases. For each test case:
- You are given an integer n, which is the number of groups.
- For each group i, you are given an integer m, the number of elements in that group.
- After that, you are given m integers, which represent the elements of the group.
You need to find the sum of the second smallest elements from all the groups, with the exception of one group, for which the smallest element should be taken instead of the second smallest. The exception group is the one that has the smallest second smallest element.

Input:
- The first input is an integer t, the number of test cases.
- For each test case:
    - The first input is an integer n, the number of groups.
    - For each group:
        - The first input is an integer m, the number of elements in that group.
        - m integers follow, which are the elements of that group.

Output:
For each test case, output a single integer: the sum of the second smallest elements of the groups, with the exception for one group, for which the smallest element is used instead.

Constraints:
- 1 <= t <= 100
- 2 <= n <= 100
- 2 <= m <= 100
- 1 <= x <= 10^9

Example:
Input:
1
3
3 1 2 3
3 2 3 4
3 3 4 5

Output:
10

Explanation:
In this case:
- For the first group, the second smallest element is 2.
- For the second group, the second smallest element is 3.
- For the third group, the second smallest element is 4.
The smallest second smallest element is 3, so the sum becomes:
2 + 3 + 4 = 9, but we replace the second smallest element from the second group (3) with the smallest element from that group (2). So, the final sum is:
2 + 2 + 4 = 10.

*/

#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define FOR(i, a, b) for (long i = a; i < b; i++)
#define FORD(i, a, b) for (long i = a; i >= b; i--)

void solve()
{
  long n; cin >> n;
  vector<pair<long, long>> v(n);
  long idx = -1, gmn = INF, gsmn = INF;
  FOR(p, 0, n)
  {
    long m; cin >> m;
    long mn = INF, smn = INF;
    FOR(q, 0, m)
    {
      long x; cin >> x;
      if (x <= mn)
      {
        smn = mn;
        mn = x;
      }
      else if (x < smn)
      {
        smn = x;
      }
    }

    v[p] = make_pair(mn, smn);
    gmn = MIN(gmn, mn);
    if (smn < gsmn)
    {
      gsmn = smn;
      idx = p;
    }
  }
  long long sum = 0;
  FOR(p, 0, n)
  {
    sum += (p != idx) ? v[p].second : gmn;
  }
  cout << sum << "\n";
}

void FastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int main()
{
  FastIO();
  long t; cin >> t;
  while (t--) solve();
  return 0;
}