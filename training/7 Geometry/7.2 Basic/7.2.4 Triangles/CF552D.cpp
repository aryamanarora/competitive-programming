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

    int n;
    cin >> n;
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    vii a(n);
    for (int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i].f == a[j].f and a[j].f == a[k].f) continue;
                if (a[i].s == a[j].s and a[j].s == a[k].s) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/