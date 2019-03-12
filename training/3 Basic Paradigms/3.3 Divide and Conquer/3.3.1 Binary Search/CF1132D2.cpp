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

    int n, k;
    cin >> n >> k;
    vl a(n); for (auto &x : a) cin >> x;
    vl b(n); for (auto &x : b) cin >> x;

    auto cmp = [](pair<ll, ll> &a, pair<ll, ll> &b) {
        return ((ld) a.f / (ld) a.s) > ((ld) b.f / (ld) b.s);
    };

    auto check = [&](ll val) {
        cout << val << endl;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            if (b[i] > 0 and (a[i] / b[i] + (a[i] % b[i] != 0) < k)) pq.push({a[i], b[i]});
        }

        ll t = 0;
        while (!pq.empty()) {
            if (t >= k) return false;
            pair<ll, ll> cur = pq.top();
            // cout << cur.f << " " << cur.s << endl;
            pq.pop();
            if (cur.f - t * cur.s < 0) return false;
            cur.f += val;
            cout << cur.f << " " << cur.s << ": " << (ld) cur.f / (ld) cur.s << endl;
            if (((ld) cur.f / (ld) cur.s) < k - 1) pq.push(cur);
            else cout << "popped" << endl;
            t++;
        }

        return true;
    };

    ll lo = 0, hi = 1e18;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2LL;
        if (check(mid)) hi = mid - 1;
        else lo = mid + 1;
    }

    if (lo >= 1e18) cout << -1 << endl;
    else cout << lo << endl;
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