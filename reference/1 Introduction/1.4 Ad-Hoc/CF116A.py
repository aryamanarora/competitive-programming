n = int(input())
p = 0
ans = 0
for i in range(n):
    a, b = map(int, input.split())
    p -= a
    p += b
    ans = max(p, ans)
print(ans)