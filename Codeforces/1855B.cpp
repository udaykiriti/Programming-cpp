/*
Codeforces Round 889 (Div. 2)
Problem B. Longest Divisors Interval
Problem link: https://codeforces.com/problemset/problem/889/B

Given a positive integer n, find the maximum size of an interval [l, r]
of positive integers such that, for every i in the interval (i.e., l ≤ i ≤ r),
n is a multiple of i.

Given two integers l ≤ r, the size of the interval [l, r] is r − l + 1
(i.e., it coincides with the number of integers belonging to the interval).

Input:
The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases.
The only line of the description of each test case contains one integer n (1 ≤ n ≤ 10^18).

Output:
For each test case, print a single integer: the maximum size of a valid interval.

Example:
Input:
10
1
40
990990
4204474560
169958913706572972
365988220345828080
387701719537826430
620196883578129853
864802341280805662
1000000000000000000

Output:
1
2
3
6
4
22
3
1
2
2

Note:
In the first test case, a valid interval with maximum size is [1, 1]
(it's valid because n=1 is a multiple of 1) and its size is 1.
In the second test case, a valid interval with maximum size is [4, 5]
(it's valid because n=40 is a multiple of 4 and 5) and its size is 2.
In the third test case, a valid interval with maximum size is [9, 11].
In the fourth test case, a valid interval with maximum size is [8, 13].
In the seventh test case, a valid interval with maximum size is [327869, 327871].
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  ll n; cin>>n;
  ll cnt(1);
  for (ll p = 2; n % p == 0 && p <= n; p++) ++cnt;
  cout<<cnt;
}

int main(int argc , char *argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  ll t; cin>>t;
  while (t--) solve();
  return 0;
}
