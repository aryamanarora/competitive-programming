"""
ID: aryaman4
LANG: PYTHON3
TASK: friday
"""

from collections import OrderedDict

fin = open('friday.in', 'r')
years = int(fin.readline().strip())
fin.close()

weekdays = [0] * 7
weekday = 2 # Monday on January 1, 1900

for year in range(1900, 1900 + years):
    months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0: # leap years
        months[1] = 29
    else:
        months[1] = 28

    for month in months:
        for day in range(1, month + 1):
            if day == 13:
                weekdays[weekday % 7] += 1
            weekday += 1

fout = open('friday.out', 'w+')
string = ""
for number in weekdays:
    string += str(number) + " "
fout.write(string.strip() + "\n")
