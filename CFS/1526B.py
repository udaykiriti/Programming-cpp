

"""
Problem: I Hate 1111
You are given an integer `n`. You need to determine if it is possible to represent `n` as the sum of some number of 11s and 111s.

Input:
The first line contains a single integer `t` (1 ≤ t ≤ 100) — the number of test cases.
Each of the next `t` lines contains a single integer `n` (1 ≤ n ≤ 10^9).

Output:
For each test case, print "YES" if it is possible to represent `n` as the sum of some number of 11s and 111s, otherwise print "NO".

Example:
Input:
3
33
144
69
Output:
YES
YES
NO
"""

def main():
    # Read the number of test cases
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        ok = False

        # Check if n can be represented as the sum of 11s and 111s
        while n > 0:
            if n % 11 == 0 or n % 111 == 0:
                ok = True
                break
            else:
                n -= 111

        # Output the result
        if ok:
            print("YES")
        else:
            print("NO")

main()