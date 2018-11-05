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

bool right_hand(const char &c) {
    return (c == 'j' or c == 'k');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool inc = true, inc2 = false, okay = true;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                if (inc2 == false) {
                    inc = false;
                    inc2 = true;
                }
                else {
                    okay = false;
                    break;
                }
            }
        }
        if (okay and !inc and inc2 and a[n - 1] > a[0]) okay = false;
        cout << (okay ? "YES" : "NO") << endl;
    }
}