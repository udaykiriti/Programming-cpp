

"""
Problem: Filling the Grid
You are given `t` test cases. For each test case, you are given an integer `n`. You need to generate a sequence of `n` integers such that:
1. The sequence starts from 3.
2. Each number in the sequence is incremented by 1.
3. If the next number is divisible by 3, skip it.

Input:
The first line contains a single integer `t` (1 ≤ t ≤ 100) — the number of test cases.
Each of the next `t` lines contains a single integer `n` (1 ≤ n ≤ 100).

Output:
For each test case, print the sequence of `n` integers on a new line.

Example:
Input:
2
5
3
Output:
3 4 6 7 9
3 4 6
"""

def main():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        current = 3
        result = []
        
        for _ in range(n):
            while current % 3 == 0:
                current += 1
            result.append(current)
            current += 2
        
        print(" ".join(map(str, result)))

main()
