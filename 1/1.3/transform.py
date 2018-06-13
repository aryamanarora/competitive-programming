"""
ID: aryaman4
LANG: PYTHON3
TASK: transform
"""

a = []
b = []
ans = 7

with open("transform.in", "r") as fin:
    n = int(fin.readline())
    for x in range(n):
        a.append(tuple(fin.readline().strip()))
    for x in range(n):
        b.append(tuple(fin.readline().strip()))

t = a

rotate = lambda x: list(zip(*x[::-1]))
reflect = lambda x : [y[::-1] for y in x]

if ans == 7:
    for i in range(1, 4):
        t = rotate(t)
        if t == b:
            ans = i
            break

t = reflect(a)
if ans == 7:
    if t == b:
        ans = 4

if ans == 7:
    for i in range(3):
        t = rotate(t)
        if t == b:
            ans = 5
            break

if ans == 7:
    if a == b: ans = 6

with open("transform.out", "w+") as fout:
    fout.write(str(ans) + "\n")
