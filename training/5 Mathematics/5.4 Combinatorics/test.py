n,a,b=int(input()),0.,[]
for i in range(n):b.append(list(map(int,input().split())))
b.append(b[0])
for i in range(n+1):a+=((b[i-1][0]-b[i][0])**2+(b[i-1][1]-b[i][1])**2)**0.5
print(round(a))