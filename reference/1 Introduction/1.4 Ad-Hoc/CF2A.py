n = int(input())
d, ledger = {}, []
for i in range(n):
    a, x = input().split()
    x = int(x)
    if a not in d:
        d[a] = 0
    d[a] += x
    ledger.append([a, x])

max_val = max(d.values())
winners = []
for key, value in d.items():
    if value == max_val:
        winners.append(key)

d = {key: 0 for key in d}
for item in ledger:
    d[item[0]] += item[1]
    if d[item[0]] >= max_val and item[0] in winners:
        print(item[0])
        break
