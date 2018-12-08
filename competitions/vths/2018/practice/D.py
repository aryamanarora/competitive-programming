from sympy import *

t = int(input())
for i in range(t):
    r1, r2, H, V = list(map(float, input().split(' ')))
    h = Symbol('h')

    f = pi * (r2 + (r1 - r2) * ((H - 2*h)**2 / (H**2)))**2

    hi = 0
    lo = 0
    while abs(hi - lo) >= 1e-7:
        mid = (hi + lo) / 2
        if integrate(f) < V:
            lo = mid
        else:
            hi = mid
    
    print(lo)
