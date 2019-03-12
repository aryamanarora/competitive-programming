n, q = map(int, input().split())
a = []
for i in range(q):
    l, r = map(int, input().split())
    l -= 1
    r -= 1
    a.append([l, r])

ct = [0] * (n + 1)
for i in a:
    ct[i[0]] += 1
    ct[i[1] + 1] -= 1

ones, twos = [0] * n, [0] * n
s = 0
for i in range(n + 1):
    if i > 0:
        ct[i] += ct[i - 1]
        ones[i] += ones[i - 1]
        twos[i] += twos[i - 1]
    if ct[i] == 1:
        ones[i] += 1
    elif ct[i] == 2:
        twos[i] += 1
    if ct[i] != 0:
        s += 1

ans = 0
for i in range(q):
    for j in range(i + 1, q):
        rem = 0;
        rem += ones[a[i][1]] - ones[a[i][0] - 1]
        rem += ones[a[j][1]] - ones[a[j][0] - 1]

        l, r = max(a[i][0], a[j][0]), min(a[i][1], a[j][1])
        if r >= l:
            rem += twos[r] - twos[l - 1]
        
        ans = max(ans, s - rem)

print(ans)