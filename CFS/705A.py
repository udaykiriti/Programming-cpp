n = int(input())
result = []

for i in range(n):
    if i % 2 == 0:
        result.append("I hate")
    else:
        result.append("I love")
    
    if i != n - 1:
        result.append("that")

result.append("it")
print(" ".join(result))
