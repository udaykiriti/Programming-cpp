/*
    Problem Number: 977A
    Problem Name: A. Wrong Subtraction
    Problem Link: https://codeforces.com/problemset/problem/977/A

    Problem Description:

    Little girl Tanya is learning how to decrease a number by one, but she does it wrong with a number consisting of two or more digits. Tanya subtracts one from a number by the following algorithm:

    - If the last digit of the number is non-zero, she decreases the number by one.
    - If the last digit of the number is zero, she divides the number by 10 (i.e. removes the last digit).

    You are given an integer number `n`. Tanya will subtract one from it `k` times. Your task is to print the result after all `k` subtractions.

    Input:
    - The first line of the input contains two integer numbers `n` and `k` (2 ≤ n ≤ 10^9, 1 ≤ k ≤ 50):
      - `n` is the number from which Tanya will subtract,
      - `k` is the number of subtractions Tanya will perform.

    Output:
    - Print one integer number — the result of decreasing `n` by one `k` times.

    It is guaranteed that the result will be a positive integer number.

    Example 1:
    Input:
    512 4
    Output:
    50

    Explanation:
    Tanya subtracts 1 from the number as follows:
    512 → 511 → 510 → 51 → 50.

    Example 2:
    Input:
    1000000000 9
    Output:
    1

    Explanation:
    Tanya subtracts 1 from the number as follows:
    1000000000 → 100000000 → 10000000 → 1000000 → 100000 → 10000 → 1000 → 100 → 10 → 1.

    Constraints:
    - 2 ≤ n ≤ 10^9
    - 1 ≤ k ≤ 50

*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, k;cin >> n>>k;
  FOR(i, 0, k)
  {
    if (n % 10 == 0) n /= 10;
    else n--;
  }
  cout << n;
}