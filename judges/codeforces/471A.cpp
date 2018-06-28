#include <iostream>

typedef long long ll;

using namespace std;

int main () {
    ll x;
    cin >> x;
    ll y;

    if (x % 2 == 0) {
        y = 4;
    }
    else {
        y = 9;
    }
    x -= y;
    cout << y << " " << x << "\n";
}