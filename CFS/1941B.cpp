/*
Problem: B. Rudolf and 121
Problem number: 933B
Link: https://codeforces.com/problemset/problem/933/B

Problem Description:
Rudolf has an array a of n integers, the elements are numbered from 1 to n.

In one operation, he can choose an index i (2 ≤ i ≤ n − 1) and assign:
- ai−1 = ai−1 − 1
- ai = ai−2
- ai+1 = ai+1 − 1

Rudolf can apply this operation any number of times. Any index i can be used zero or more times.

Can he make all the elements of the array equal to zero using this operation?

Input:
- The first line of the input contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases in the test.
- The first line of each case contains a single integer n (3 ≤ n ≤ 2 * 10^5) — the number of elements in the array.
- The second line of each case contains n integers a1, a2, ..., an (0 ≤ aj ≤ 10^9) — the elements of the array.

It is guaranteed that the sum of the values of n over all test cases does not exceed 2 * 10^5.

Output:
- For each test case, output "YES" if it is possible to make all the elements of the array zero using the described operations. Otherwise, output "NO".

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

Example:
Input:
7
5
1 3 5 5 2
5
2 4 4 5 1
5
0 1 3 3 1
6
5 6 0 2 3 0
4
1 2 7 2
3
7 1 0
4
1 1 1 1

Output:
YES
NO
YES
NO
NO
NO
NO

Note:
In the first example, the original array is [1, 3, 5, 5, 2], to make all its elements zero, Rudolf can act as follows:
- Apply the operation at i = 4 and get the array [1, 3, 4, 3, 1];
- Apply the operation at i = 3 and get the array [1, 2, 2, 2, 1];
- Apply the operation at i = 2 and get the array [0, 0, 1, 2, 1];
- Apply the operation at i = 4 and get the array [0, 0, 0, 0, 0].
*/

#include <cstdio>
#include <vector>

int main()
{

  long t; scanf("%ld", &t);
  while (t--)
  {
    long n; scanf("%ld", &n);
    std::vector<long> a(n);
    for (long p = 0; p < n; p++)
    {
      scanf("%ld", &a[p]);
    }
    bool valid(true);
    for (long p = 0; valid && p + 2 < n; p++)
    {
      if (a[p] < 0)
      {
        valid = false;
      }
      a[p + 1] -= 2 * a[p];
      a[p + 2] -= a[p];
    }

    valid = valid && !a[n - 2] && !a[n - 1];
    puts(valid ? "YES" : "NO");
  }
}