a = input().lower()
a = "".join(list(filter(lambda x: "." + x if x not in "aeiouy" else "", list(a))))
