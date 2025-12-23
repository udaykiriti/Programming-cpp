/*
    Problem Number: A. Nearly Lucky Number
    Problem Link: https://codeforces.com/problemset/problem/110/A


    Problem Description:

    Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

    Unfortunately, not all numbers are lucky. Petya calls a number nearly lucky if the number of lucky digits in it is a lucky number. He wonders whether number `n` is a nearly lucky number.

    Input:
    - The only line contains an integer `n` (1 ≤ n ≤ 10^18).

    Output:
    - Print on the single line "YES" if `n` is a nearly lucky number. Otherwise, print "NO" (without the quotes).

    Examples:
    1. Input: 40047
       Output: NO
    2. Input: 7747774
       Output: YES
    3. Input: 1000000000000000000
       Output: NO

    Note:
    - In the first sample there are 3 lucky digits (first one and last two), so the answer is "NO".
    - In the second sample there are 7 lucky digits, 7 is a lucky number, so the answer is "YES".
    - In the third sample there are no lucky digits, so the answer is "NO".
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll n; cin >> n;
  int check = 0;
  int rem;
  while (n != 0)
  {
    rem = n % 10;
    n /= 10;
    if (rem == 7 || rem == 4)
      check++;
  }
  if (check != 4 && check != 7)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}