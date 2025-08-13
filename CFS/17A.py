import math

N = 1000
pr = [True] * (N + 1)
pr[0] = pr[1] = False

for i in range(2, int(math.sqrt(N)) + 1):
    if pr[i]:
        for j in range(i * i, N + 1, i):
            pr[j] = False

prs = [i for i in range(2, N + 1) if pr[i]]

cb = [False] * (N + 1)
for i in range(len(prs) - 1):
    ele = prs[i] + prs[i + 1] + 1
    if ele > N:
        break
    if pr[ele]:
        cb[ele] = True

N_input, k = map(int, input().split())
count = 0

for i in range(2, N_input + 1):
    if cb[i]:
        count += 1

print('YES' if count >= k else 'NO')
