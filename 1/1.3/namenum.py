"""
ID: aryaman4
LANG: PYTHON3
TASK: namenum
"""

import string

alpha, key = "ABCDEFGHIJKLMNOPRSTUVWXY", {}
for i in range(8):
    for j in range(3):
        key[alpha[i * 3 + j]] = i + 2
print(key)

d = {}
for line in open('dict.txt'):
    line = line.rstrip()
    if not ("Z" in line or "Q" in line):
        x = ""
        for letter in line:
            x += str(key[letter])
        x = int(x)
        if not x in d:
            d[x] = []
        d[x].append(line)

a = None
with open("namenum.in", "r") as fin:
    a = int(fin.readline().rstrip())

with open("namenum.out", "w+") as fout:
    if a in d:
        for name in d[a]:
            fout.write(name + "\n")
    else:
        fout.write("NONE\n")
