def solve():
  s=input()
  if s=='abc':
    print("YES")
  else:
    m=0
    for i in range(0,3):
      if s[i]!='abc'[i]:
        m+=1
    print('YES' if m==2 else 'NO')

t=int(input())
for _ in range(t):
  solve()