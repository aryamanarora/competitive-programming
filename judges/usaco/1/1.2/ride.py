"""
ID: aryaman4
LANG: PYTHON3
TASK: ride
"""

import string

key = dict(zip(string.ascii_uppercase, list(range(1, 27))))

fin = open('ride.in', 'r')
comet, group = fin.readline().rstrip(), fin.readline().rstrip()
fin.close()

comet_score, group_score = 1, 1
for letter in comet: comet_score *= key[letter]
for letter in group: group_score *= key[letter]

comet_score, group_score = comet_score % 47, group_score % 47

fout = open('ride.out', 'w+')
if comet_score == group_score:
    fout.write('GO\n')
else:
    fout.write('STAY\n')
