"""
ID: aryaman4
LANG: PYTHON3
TASK: combo
"""

n, john, master = 0, [], []
with open("combo.in", "r") as fin:
    n = int(fin.readline().strip())
    john = list(map(int, fin.readline().split()))
    master = list(map(int, fin.readline().split()))

allowed_john, allowed_master = [], []

tolerance = lambda x: [x - 2, x - 1, x, x + 1, x + 2]


for i in range(3):
    a, b = john[i], master[i]
    c, d = [x % n + 1 for x in list(set(tolerance(a)))], [x % n + 1 for x in list(set(tolerance(b)))]
    allowed_john.append(c)
    allowed_master.append(d)

allowed = []

# O(N^3), inefficient, I know... but it gets the job done!
for i in allowed_john[0]:
    for j in allowed_john[1]:
        for k in allowed_john[2]:
            if [i, j, k] not in allowed:
                allowed.append([i, j, k])

for i in allowed_master[0]:
    for j in allowed_master[1]:
        for k in allowed_master[2]:
            if [i, j, k] not in allowed:
                allowed.append([i, j, k])

ans = len(allowed)

with open("combo.out", "w+") as fout:
    fout.write(str(ans) + "\n")
