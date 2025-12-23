def solve():
  n=int(input())
  print('second' if n%3==0 else 'second')

t=int(input())
for i in range(t):
  solve()