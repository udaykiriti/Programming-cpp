a = input()
b = input()

result = ''
for i in range(len(a)):
    result += str(int(a[i]) ^ int(b[i]))

print(result)
