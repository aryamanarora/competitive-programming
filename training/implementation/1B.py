import re, math, string

alpha = string.ascii_uppercase

n = int(input())
inputs = []
for i in range(n):
    inputs.append(input())

def num_to_letter(x):
    x = int(x)
    s = ""
    while x > 0:
        if x % 26 == 0:
            x = int(x / 26 - 1)
            s += alpha[25]
        else:
            x, k = divmod(x, 26)
            s += alpha[int(k - 1)]
    return s[::-1]

def letter_to_num(x):
    num = 0
    for i in range(len(x)):
        if x[i] == alpha[25]:
            num = 26*(num + 1)
        else:
            k = alpha.index(x[i]) + 1
            num = num * 26 + k
    return str(num)

for i in inputs:
    reg = re.compile('R([0-9]+)C([0-9]+)')
    x = reg.fullmatch(i)
    if x is not None:
        print(num_to_letter(x.group(2)) + x.group(1))
    excel = re.compile('([A-Z]+)([0-9]+)')
    y = excel.fullmatch(i)
    if y is not None:
        print("R" + y.group(2) + "C" + letter_to_num(y.group(1)))
