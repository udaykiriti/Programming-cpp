ret = 0
prev = ''
for _ in range(int(input())):
    curr = input()
    if curr != prev:
        ret += 1
        prev = curr
print(ret)