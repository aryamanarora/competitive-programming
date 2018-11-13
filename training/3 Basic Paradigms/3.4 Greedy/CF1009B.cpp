#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

int main() {
    string s;
    cin >> s;
    int one = 0;
    for (char &x : s) if (x == '1') one++;
    bool printed = false;
    for (char &x : s) {
        if (x == '0') cout << x;
        else if (x == '2') {
            if (!printed) {
                for (int i = 0; i < one; i++) cout << '1';
                printed = true;
            }
            cout << '2';
        }
    }
    if (!printed)
        for (int i = 0; i < one; i++) cout << '1';
    cout << "\n";
}