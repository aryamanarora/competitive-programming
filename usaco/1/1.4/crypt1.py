"""
ID: aryaman4
LANG: PYTHON3
TASK: crypt1
"""

from itertools import product

ans = 0

n, ns = 0, []
with open("crypt1.in", "r") as fin:
    n = int(fin.readline().strip())
    ns = list(map(int, fin.readline().split()))
ns = "".join(str(x) for x in ns)

x = list(int("".join(x)) for x in product(ns, repeat = 3))
y = list(int("".join(x)) for x in product(ns, repeat = 2))

ns = set(ns)

for a in x:
    for b in y:
        z = str(a * b)
        p1 = str(a * (b % 10))
        p2 = str(a * (b // 10))
        if len(z) == 4 and len(p1) == 3 and len(p2) == 3:
            if set(z).issubset(ns) and set(p1).issubset(ns) and set(p2).issubset(ns):
                ans += 1

with open("crypt1.out", "w+") as fout:
    fout.write(str(ans) + "\n")
