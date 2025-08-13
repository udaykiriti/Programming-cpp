n = int(input())

evn = n // 2
oddn = n // 2 if n % 2 == 0 else n // 2 + 1

sumevn = evn * (evn + 1)
sumoddn = oddn * oddn

sum_result = sumevn - sumoddn

print(sum_result)
