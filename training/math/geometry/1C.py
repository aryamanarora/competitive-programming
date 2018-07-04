from math import *

def gcd(a,b) :
    if b < pi/100:
        return a
    return gcd(b, fmod(a, b))

x = []
for i in range(3):
    x.append(list(map(float, input().split())))

A, B, C = x

dist = lambda x, y: sqrt((y[1] - x[1])**2 + (y[0] - x[0])**2)
a, b, c = dist(B, C), dist(A, C), dist(A, B)

s = (a + b + c) / 2
k = sqrt(s*(s-a)*(s-b)*(s-c))

R = (a * b * c) / (4 * k) # radius of circumcircle
α, β, γ = acos(round((b**2 + c**2 - a**2) / (2 * b * c), 8)),\
            acos(round((a**2 + c**2 - b**2) / (2 * a * c), 8)),\
            acos(round((a**2 + b**2 - c**2) / (2 * a * b), 8))
n = pi / gcd(α, gcd(β, γ))

print(round(0.5 * n * R**2 * sin((2 * pi) / n), 8))
