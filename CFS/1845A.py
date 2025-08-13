"""
Problem: Forbidden Value
You are given three integers n, k, x.
You need to represent n as the sum of some positive integers, each between 1 and k (inclusive), and none of them equal to x.
If possible, print "YES" and the number of summands, followed by the summands themselves.
Otherwise, print "NO".

Input:
The first line contains a single integer t (number of test cases).
Each test case contains three integers n, k, x.

Output:
For each test case, print the answer as described above.
"""

def solve():
    n, k, x = map(int, input().split())
    if x == 1 and k == 1:
        print("NO")
    elif x == 1 and k == 2 and n % 2 == 1:
        print("NO")
    else:
        if x != 1:
            print("YES")
            print(n)
            print(' '.join(['1'] * n))
        else:
            if n % 2 == 1:
                print("YES")
                cnt = 1 + (n - 3) // 2
                print(cnt)
                print('3', end=' ')
                n -= 3
                print(' '.join(['2'] * (n // 2)))
            else:
                print("YES")
                print(n // 2)
                print(' '.join(['2'] * (n // 2)))

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()