n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
print(len(list(filter(lambda x: (x >= a[k-1] and x > 0), a))))
