"""
ID: aryaman4
LANG: PYTHON3
TASK: dualpal
"""

nums = "0123456789ABCDEFGHIJKLMONQRSTUVWXYZ"
N, S = 0, 0
with open("dualpal.in", "r") as fin:
    N, S = list(map(int, fin.readline().rstrip().split()))

def conv(x, b):
    z = 0
    if x < b:
        return nums[x]
    else:
        return conv(x // b, b) + nums[x % b]

Ns = []
S += 1
while len(Ns) < N:
    reps = 0
    for base in range(2, 11):
        if conv(S, base) == conv(S, base)[::-1]:
            reps += 1
    if reps >= 2:
        Ns.append(S)
    S += 1

with open("dualpal.out", "w+") as fout:
    [fout.write(str(x) + "\n") for x in Ns]
