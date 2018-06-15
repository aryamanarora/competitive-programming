import math

[n, m, a] = list(map(float, input().split()))
x = math.ceil(m / a) * math.ceil(n / a)
print(x)
