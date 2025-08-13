/*
    Problem Number:2004A
    Problem Name: A. Closest Point
    Codeforces Username:Polymath__
    GitHub Link: https://github.com/udaykiriti
    Problem Link: https://codeforces.com/problemset/problem/2004/A
*/

/*
    Problem Statement:
    Consider a set of points on a line. The distance between two points i and j is |i−j|.
    The point i from the set is the closest to the point j from the set, if there is no other point k
    in the set such that the distance from j to k is strictly less than the distance from j to i.

    The task is to determine if it is possible to add a new point to the set such that:
    1. The new point is different from every existing point.
    2. The new point becomes the closest point to every point in the set.

    Input:
    - The first line contains one integer t (1 ≤ t ≤ 1000), the number of test cases.
    - For each test case:
        - The first line contains one integer n (2 ≤ n ≤ 40), the number of points in the set.
        - The second line contains n integers x1, x2, ..., xn (1 ≤ x1 < x2 < ... < xn ≤ 100), the points in the set.

    Output:
    - For each test case, print "YES" if it is possible to add a new point according to the conditions, otherwise print "NO".

    Approach:
    - In order for a new point to be the closest to all points in the set, it should be placed in the middle of the largest gap between consecutive points in the set.
    - If the largest gap between two consecutive points is greater than or equal to 2, we can place a point in the middle, and it will be the closest to both points.
    - If the largest gap between any two consecutive points is 1, then no point can be added that is closer to both points than the existing ones.

    Plan:
    1. For each test case:
        - Check the gaps between consecutive points.
        - If there is a gap greater than or equal to 2, print "YES".
        - If all gaps are 1, print "NO".

    Example Walkthrough:
    - Test Case 1:
        - Points: [3, 8], Gap = 5. A point 7 can be added to be closest to both 3 and 8, print "YES".
    - Test Case 2:
        - Points: [5, 6], Gap = 1. No point can be added between 5 and 6, print "NO".
    - Test Case 3:
        - Points: [1, 2, 3, 4, 5, 10], Gaps: [1, 1, 1, 1, 5]. No valid gaps for adding a point, print "NO".
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)

void solve()
{
  int n; cin >> n;
  vector<int> x(n);
  FOR (i ,0, n) 
    cin >> x[i];
  if (n == 2 && x[0] + 2 <= x[1])
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}