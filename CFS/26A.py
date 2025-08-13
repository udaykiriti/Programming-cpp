def solve(n):
    cnt = [0] * (n + 1)
    for i in range(2, n + 1):
        if cnt[i] == 0: 
            for j in range(i, n + 1, i):
                cnt[j] += 1
    result = 0
    for i in range(1, n + 1):
        if cnt[i] == 2:
            result += 1
    print(result)

n = int(input())
solve(n)