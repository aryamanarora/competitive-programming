#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    cin >> a;

    vi ab, ba;
    for (int i = 0; i < a.length() - 1; i++) {
        if (a[i] == 'A' and a[i+1] == 'B') {
            ab.pb(i)
        }
        if (a[i] == 'B' and a[i+1] == 'A') {
            ba.pb(i);
        }
    }

    for (auto &x : ab) {
        for (auto &y : ba) {
            if (ab != ba + 1 and ab != ba - 1) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    vector<int> test;
    return 0;
}