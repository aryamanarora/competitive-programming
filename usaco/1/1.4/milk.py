"""
ID: aryaman4
LANG: PYTHON3
TASK: milk
"""

n, m, cost, market = None, None, 0, []
with open("milk.in", "r") as fin:
    n, m = list(map(int, fin.readline().strip().split()))
    for i in range(m):
        market.append(list(map(int, fin.readline().strip().split())))

market = sorted(market)
for farmer in market:
    if farmer[1] > n:
        cost += farmer[0] * n
        break
    else:
        cost += farmer[0] * farmer[1]
        n -= farmer[1]

with open("milk.out", "w+") as fout:
    fout.write(str(cost) + "\n")
