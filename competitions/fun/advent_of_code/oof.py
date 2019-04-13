twos = 0
threes = 0
chars = 'abcdefghijklmnopqrstuvwxyz'
while True:
    two = False
    three = False
    i = input()
    for char in chars:
        if i.count(char) == 2:
            two = True
        elif i.count(char) == 3:
            three = True
    if two:
        twos += 1
    if three:
        threes += 1
    print(twos*threes)
        