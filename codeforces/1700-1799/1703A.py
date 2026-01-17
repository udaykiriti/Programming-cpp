
"""
Problem: YES or YES?
You are given a string s consisting of three letters. Your task is to determine if the string matches the word "YES" in any case (uppercase, lowercase, or mixed).

Input:
The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases.
Each of the next t lines contains a single string s consisting of exactly three letters.

Output:
For each test case, print "YES" if the string matches "YES" in any case, otherwise print "NO".

Example:
Input:
3
yEs
yes
no
Output:
YES
YES
NO
"""

t = int(input())

while t > 0:
    t -= 1
    s = input()
    if s.upper() == 'YES':
        print("YES")
    else:
        print("NO")
