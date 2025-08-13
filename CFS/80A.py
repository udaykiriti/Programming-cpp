import math
N=100
p=[True]*(N+1)
p[0]=p[1]=False
primes=[]

for i in range(2,int(math.sqrt(N))):
  if p[i]:
    for j in range(i*i,N,i):
      p[j]=False
for i in range(N):
  if p[i]:
    primes.append(i)

def solve(now,next):
  for i in range(0,len(primes)):
    if primes[i]==now:
      if i+1<len(primes) and primes[i+1]==next:
        print('YES')
      else:
        print('NO')
      return
  print('NO')

now,next=map(int,input().split())
solve(now,next)