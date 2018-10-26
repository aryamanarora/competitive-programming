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

const int MAX = 201;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, a;
    cin >> t;
    while (t--) {
        cin >> n >> a;
        ll pos = 1, cur = a, last;
        for (int day = 1;; day++) {
            last = cur;
            for (ll i = 0; i < last and pos < n; i++) {
                cin >> a;
                cur += a;
                pos++;
            }
            if (pos >= n) {
                cout << day << endl;
                break;
            }
        }
    }
}