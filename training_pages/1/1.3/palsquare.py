"""
ID: aryaman4
LANG: PYTHON3
TASK: palsquare
"""

nums = "0123456789ABCDEFGHIJKLMONQRSTUVWXYZ"
base = 0
with open("palsquare.in", "r") as fin:
    base = int(fin.readline().rstrip())

nums = nums[:base]
def conv(x, b):
    z = 0
    if x < b:
        return nums[x]
    else:
        return conv(x // b, b) + nums[x % b]

with open("palsquare.out", "w+") as fout:
    for i in range(1, 33301):
        y = conv(i**2, base)
        i = conv(i, base)
        if y == y[::-1]:
            fout.write(i + " " + y + "\n")
