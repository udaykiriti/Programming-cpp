
def sumo(n):
  temp=n
  total=0
  while temp:
    total+=temp%10
    temp//=10
  return total

def solve():
  n=int(input())
  s=sumo(n)
  while s>=10:
    s=sumo(s)
  print(s)

#t=int(input())
t=1
for i in range(t):
  solve()
