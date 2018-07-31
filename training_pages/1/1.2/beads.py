"""
ID: aryaman4
LANG: PYTHON3
TASK: beads
"""

import re

fin = open('beads.in', 'r')
length = int(fin.readline().strip())
necklace = fin.readline().strip()
fin.close()

necklace *= 2
print(necklace)
match_lengths = []

for i in range(length):
    test = necklace[i:i+length]
    matches = [re.match(r"[wb]*[wr]*", test), re.match(r"[wr]*[wb]*", test)]
    for match in matches:
        if match is not None:
            match_lengths.append(len(match.group()))

fout = open('beads.out', 'w+')
fout.write(str(max(match_lengths)) + "\n")
fout.close()
