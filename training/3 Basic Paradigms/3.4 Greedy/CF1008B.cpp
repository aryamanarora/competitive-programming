#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ll n;
    cin >> n;
    ll prev = 10e10;
    ll current1, current2;
    bool ans = true;
    for (int i = 0; i < n; i++) {
        cin >> current1 >> current2;
        if (min(current1, current2) > prev) {
            ans = false;
            break;
        }
        else {
            if (max(current1, current2) <= prev) {
                prev = max(current1, current2);
            }
            else prev = min(current1, current2);
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
}