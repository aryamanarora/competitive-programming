"""
ID: aryaman4
LANG: PYTHON3
TASK: barn1
"""

m, s, c = 0, 0, 0
x = [] # occupied stalls
with open("barn1.in", "r") as fin:
    m, s, c = list(map(int, fin.readline().split()))
    for i in range(c):
        x.append(int(fin.readline().strip()))

x = sorted(x)
g = [] # gaps

for n in range(1, len(x)):
    g.append((x[n] - x[n - 1]) - 1)

g = sorted(g)[::-1][:m - 1]
ans = max(x) - min(x) + 1 - sum(g)

with open("barn1.out", "w+") as fout:
    fout.write(str(ans) + "\n")
