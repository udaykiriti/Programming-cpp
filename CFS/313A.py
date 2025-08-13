n=int(input())
if n>=0:
    print(n)
else:
    r1=n//10
    r2=(n//100)*10+n%10
    print(max(r1,r2))