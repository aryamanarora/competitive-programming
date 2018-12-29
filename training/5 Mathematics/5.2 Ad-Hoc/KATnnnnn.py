# https://oeis.org/A110803

from math import sqrt

l = int(input())

lo = 1
hi = sqrt(len(str(l))) // 1
while lo <= hi:
    mid = (lo + hi) // 2
    print(lo)
    if len(str(l // mid)) > mid:
        lo = mid + 1
    else:
        hi = mid - 1
print(l // lo)

"""
9 9
10 20
11 22
...
99 198
100 300
"""