#include <bits/stdc++.h>

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
    int n;
    cin >> n;
    vi a(n);
    cin >> a[0];
    bool increasing = false;
    int l, r;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] < a[i-1] and !increasing) {
            increasing = true;
            l = i-1;
        };
        if (a[i] > a[i-1] and increasing) {
            increasing = false;
            r = i-1;
        }
    }
    reverse(a.begin() + l, a.begin() + r);
    bool sorted = true;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n" << l + 1 << " " << r + 1 << "\n";
}