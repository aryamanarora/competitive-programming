"""
ID: aryaman4
LANG: PYTHON3
TASK: fact4
"""

import re, math

fin = open('fact4.in', 'r')
n = int(fin.readline().strip())
necklace = fin.readline().strip()
fin.close()

ans = str(math.factorial(n))
print(ans)
ans = ans.rstrip("0")[-1]

fout = open('fact4.out', 'w+')
fout.write(ans + "\n")
fout.close()
