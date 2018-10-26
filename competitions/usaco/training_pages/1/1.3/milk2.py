"""
ID: aryaman4
LANG: PYTHON3
TASK: milk2
"""

intervals = []

with open("milk2.in", "r") as fin:
    l = int(fin.readline())
    for x in range(l):
        intervals.append(list(map(int, fin.readline().split(" "))))

# x[0] < y[0] for these
overlap = lambda x, y: x[1] >= y[0]
def merge(x, y):
    if y[1] > x[1]:
        return [x[0], y[1]]
    elif x[1] > y[1]:
        return [x[0], x[1]]
    else:
        return [x[0], x[1]]

intervals = sorted(intervals)
j = [intervals[0]]
intervals = intervals[1:]
while len(intervals) > 0:
    if overlap(j[-1], intervals[0]):
        j[-1] = merge(j[-1], intervals[0])
    else:
        j.append(intervals[0])
    del intervals[0]

print(j)

last_interval = j[0]
max_interval, max_gap = last_interval[1] - last_interval[0], 0

for interval in j[1:]:
    y = interval[1] - interval[0]
    max_interval = y if y > max_interval else max_interval

    z = interval[0] - last_interval[1]
    max_gap = z if z > max_gap else max_gap

    last_interval = interval

with open("milk2.out", "w+") as fout:
    fout.write(str(max_interval) + " " + str(max_gap) + "\n")
