"""
ID: aryaman4
LANG: PYTHON3
TASK: gift1
"""

from collections import OrderedDict

ledger = [line.rstrip() for line in open('gift1.in')]
people = OrderedDict()
num = int(ledger.pop(0))

for person in range(num):
    people[ledger[0]] = 0
    ledger.pop(0)

while len(ledger) > 0:
    i = 0
    gifter = ledger[i]
    i += 1

    money, recipients = map(int, ledger[i].split())
    i += 1
    recipients = ledger[i:i+recipients]

    if len(recipients) != 0:
        gift, gain = divmod(money, len(recipients))
        people[gifter] += (gain - money)

        for recipient in recipients:
            people[recipient] += gift

    del ledger[0:i+len(recipients)]

fout = open('gift1.out', 'w+')
for person in people:
    fout.write(person + ' ' + str(people[person]) + '\n')
fout.close()
