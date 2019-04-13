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

template<typename T>
T least_significant_one(T x) {
    return (x & (-x));
}

struct fenwick_tree {
    int n;
    vl freq, ct;
    fenwick_tree(int N) : n(N), freq(N + 1, 0), ct(N + 1, 0) {};
    ll sum(int a) {
        ll res = 0;
        for (; a; a -= least_significant_one(a)) res += freq[a];
        return res;
    }
    ll count(int a) {
        ll res = 0;
        for (; a; a -= least_significant_one(a)) res += ct[a];
        return res;
    }
    ll num(int a) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (count(mid) < a) lo = mid + 1;
            else hi = mid - 1;
        }
        return sum(lo) - (count(lo) - a) * lo;
    }
    void add(int a, int v) {
        for (; a <= n; a += least_significant_one(a)) freq[a] += v, ct[a]++;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vii a(n);

    ll cur = 0;
    for (auto &x : a) cin >> x.f;
    for (auto &x : a) cin >> x.s, cur += x.s;
    sort(a.begin(), a.end());
    
    fenwick_tree ft(250);
    ll ans = cur;
    for (int i = 0; i < n;) {
        int j;
        for (j = i; j < n; j++) {
            if (a[j].f == a[i].f) {
                cur -= a[j].s;
            }
            else break;
        }
        int need = max(0, i - (j - i - 1));
        // cout << a[i].f << ": " << need << " " << cur << " " << ft.num(need) << endl;
        ans = min(ans, cur + ft.num(need));
        for (int k = i; k < j; k++) {
            ft.add(a[k].s, a[k].s);
        }
        i = j;
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