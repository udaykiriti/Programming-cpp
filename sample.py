t = int(input())
cases = [int(input()) for _ in range(t)]
for n in cases:
    print((n * n) // 4 + 1)