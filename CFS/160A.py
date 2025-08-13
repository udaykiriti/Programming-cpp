n = int(input())
arr = list(map(int, input().split()))
arr.sort()

sum1 = sum(arr[:-1])
sum2 = arr[-1]

i = 1
while i <= n:
    if sum2 > sum1:
        print(i)
        break
    else:
        i += 1
        sum2 += arr[-i]
        sum1 -= arr[-i]
