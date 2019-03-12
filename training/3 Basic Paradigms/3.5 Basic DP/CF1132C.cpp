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

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vii a(q); for (auto &[l, r] : a) cin >> l >> r, l--, r--;

    vi ct(n + 1);
    for (auto &[l, r] : a) ct[l]++, ct[r + 1]--;

    vi ones(n + 1), twos(n + 1);
    ll sum = 0;
    for (int i = 0; i <= n; i++) {
        if (i > 0) ct[i] += ct[i - 1], ones[i] += ones[i - 1], twos[i] += twos[i - 1];
        if (ct[i] == 1) ones[i]++;
        else if (ct[i] == 2) twos[i]++;
        if (ct[i]) sum++;
    }

    // for (auto &x : ct) cout << x << " ";
    // cout << endl;

    auto range_sum = [](vi &a, int l, int r) {
        return (a[r] - (l == 0 ? 0 : a[l - 1]));
    };

    ll ans = 0;
    for (int i = 0; i < q; i++) {
        for (int j = i + 1; j < q; j++) {
            ll rem = 0;
            rem += range_sum(ones, a[i].f, a[i].s);
            rem += range_sum(ones, a[j].f, a[j].s);

            int l = max(a[i].f, a[j].f), r = min(a[i].s, a[j].s);
            if (l <= r) rem += range_sum(twos, l, r);

            ans = max(ans, sum - rem);
            // cout << i << " " << j << ": " << rem << endl;
        }
    }

    cout << ans << endl;
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:
:pray: :prodakcin:

          .=     ,        =.
  _  _   /'/    )\,/,/(_   \ \
   `//-.|  (  ,\\)\//\)\/_  ) |
   //___\   `\\\/\\/\/\\///'  /
,-"~`-._ `"--'_   `"""`  _ \`'"~-,_
\       `-.  '_`.      .'_` \ ,-"~`/
 `.__.-'`/   (-\        /-) |-.__,'
   ||   |     \O)  /^\ (O/  | .        <-  BESSIE THE COW
   `\\  |         /   `\    /
     \\  \       /      `\ /
      `\\ `-.  /' .---.--.\
        `\\/`~(, '()      ('
         /(O) \\   _,.-.,_)    
        //  \\ `\'`      /
       / |  ||   `""""~"`
     /'  |__||
           `o
*/