n = int(input())
ans = 0
fac = 1
for i in range(n + 1):
    if i == 0 or i == 1:
        ans += 1 / fac
    else:
        fac *= i
        ans += 1 / fac
print(ans)