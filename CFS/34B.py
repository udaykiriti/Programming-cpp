n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

count = 0
for i in range(m):
    if arr[i] < 0:
        count -= arr[i]

print(count)
