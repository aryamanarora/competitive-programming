#include <map>
#include <iostream>

using namespace std;

int main() {
    map<int, int> months = {
        {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}
    };

    int m, d;
    cin >> m >> d;
    d += months[m];
    d--;
    if (d % 7 == 0) d /= 7;
    else d = d/7 + 1;

    cout << d << "\n";
}