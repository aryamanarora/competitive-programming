"""
ID: aryaman4
LANG: PYTHON3
TASK: test
"""
fin = open('test.in', 'r')
x, y = map(int, fin.readline().split())
fin.close()

sum = x + y
fout = open('test.out', 'w+')
fout.write(str(sum) + '\n')
fout.close()
