#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int a, b, c, d;
    scanf("%i %i %i %i", &a, &b, &c, &d);

    if (a == c && b != d) {
        cout << a + abs(b - d) << " " << b << " " << a + abs(b - d) << " " << d;
    }
    else if (b == d) {
        cout << a << " " << b + abs(a - c) << " " << c << " " << b + abs(a - c);
    }
    else if (abs(d - b) == abs(c - a)) {
        cout << a << " " << d << " " << c << " " << b;
    }
    else {
        cout << "-1";
    }

    cout << endl;
}