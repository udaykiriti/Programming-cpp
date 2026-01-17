/*
 problem Number: 546A
 Problem Name: A. Soldier and Bananas
 Problem Link: https://codeforces.com/problemset/problem/546/A

*/
/*
    Problem Description:

    A soldier wants to buy `w` bananas in the shop. He has to pay `k` dollars for the first banana,
    `2k` dollars for the second one, and so on (in other words, he has to pay `i·k` dollars for the `i-th` banana).

    He has `n` dollars. The task is to determine how many dollars he has to borrow from his friend to buy `w` bananas.

    Input:
    - The first line contains three positive integers `k, n, w`:
        - `k` is the cost of the first banana,
        - `n` is the initial number of dollars the soldier has,
        - `w` is the number of bananas he wants to buy.

    Output:
    - Output one integer — the amount of dollars that the soldier must borrow from his friend.
      If he doesn't have to borrow money, output 0.

    Example 1:
    Input:
    3 17 4
    Output:
    13

    Explanation:
    The cost of the bananas is:
    3 + 6 + 9 + 12 = 30 (total cost)
    The soldier has 17 dollars, so he needs to borrow 30 - 17 = 13 dollars.

    Example 2:
    Input:
    1 1 1
    Output:
    0

    Explanation:
    The cost of the first banana is 1, and the soldier has exactly 1 dollar, so no money needs to be borrowed.

    Constraints:
    - 1 ≤ k, w ≤ 1000
    - 0 ≤ n ≤ 10^9
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); 
  int k, n, w; cin >> k>>n>>w;
  int sum = 0;
  for (int i = 1; i <= w; i++)
    sum += i * k;
  int b = (sum - n) > 0 ? (sum - n) : 0;
  cout << b;
  return 0;
}
