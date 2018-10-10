s = input().strip()
if s.isupper():
    print(s.lower())
elif s[0].islower() and (len(s) == 1 or s[1:].isupper()):
    print(s[0].upper() + s[1:].lower())
else:
    print(s)