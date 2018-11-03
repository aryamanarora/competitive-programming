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

int n, k;

int comp(int x) {
    return (x ^ ((2 << k) - 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int c;
    map<int, int> ct, xorct;
    
    ll ans = 0;
    int curxor = 0, curseg = 0;
    for (auto &x : a) {
        c = comp(x);
        if (ct[x] > ct[c]) {
            x = c;
            ct[c]++;
        }
        else ct[x]++;
        cout << x << " ";

        curxor ^= x;
        if (xorct[curxor] > 0) {
            ans += (curseg * (curseg + 1)) / 2;
            curseg = 0;
            xorct[curxor] = 0;
        }
        else xorct[curxor]++;
        curseg++;
    }
    cout << endl;

    cout << ans << endl;
}