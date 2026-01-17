/* Problem: IQ test
Bob is preparing to pass an IQ test. The most frequent task in this test is to find out which one of the given n numbers differs from the others. Bob observed that one number usually differs from the others in evenness. Help Bob — to check his answers, he needs a program that among the given n numbers finds one that is different in evenness.

Input:
The first line contains a single integer n (3 ≤ n ≤ 100) — the number of numbers in the task.
The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 100).

Output:
Output the 1-based index of the number that differs from the others in evenness.

Example:
Input:
5
2 4 7 8 10
Output:
3

Input:
4
1 2 1 1
Output:
2
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

int main()
{
  FastIO;
  int n; cin >> n;
  vector<int> nums(n);
  FOR(i, 0, n)
    cin >> nums[i];
  int even_count = 0;
  FOR(i, 0, n)
    if (nums[i] % 2 == 0)
      even_count++;
  FOR(i, 0, n)
  {
    if ((even_count > 1 && nums[i] % 2 != 0) || (even_count == 1 && nums[i] % 2 == 0))
    {
      cout << i + 1 << endl;
      break;
    }
  }
  return 0;
}