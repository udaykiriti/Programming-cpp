def solve():
    n = int(input())
    a = list(map(int, input().split()))  
    maxb = 0  
    curr = 0  

    for i in range(n):
        if a[i] == 0:
            curr += 1
            maxb = max(maxb, curr)
        else:
            curr = 0  
    print(maxb)



t=int(input())
for _ in range(t):
    solve()