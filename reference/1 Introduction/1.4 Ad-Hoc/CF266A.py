n = int(input())
s = input().strip()

ans = 0
last = s[0]
for i in range(1, n):
    if s[i] == last:
        ans += 1
    last = s[i]

print(ans)