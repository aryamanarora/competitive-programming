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
    vl freq;
    fenwick_tree(int N) : n(N), freq(N + 1, 0) {};
    ll sum(int a) {
        ll res = 0;
        for (; a; a -= least_significant_one(a)) res += freq[a];
        return res;
    }
    void add(int a, int v) {
        for (; a <= n; a += least_significant_one(a)) freq[a] += v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi a(n); for (auto &x : a) cin >> x;
    vi pos(n + 1); for (int i = 0; i < n; i++) pos[a[i]] = i;

    vl ans(4);

    fenwick_tree sw(n);
    for (int i = 0; i < n; i++) sw.add(i + 1, 1);
    for (int i = 1; i <= n; i++) {
        ans[0] += sw.sum(pos[i]);
        sw.add(pos[i] + 1, -1);
    }

    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int ct = 0;
        for (int j = i; !vis[j]; j = a[j - 1], ct++) {
            vis[j] = true;
        }
        ans[1] += ct - 1;
    }

    set<ii> lis;
    for (auto &x : a) {
        auto it = lis.lower_bound({x, 0});
        int ct = (it == lis.begin() ? 0 : prev(it)->s + 1);
        auto it2 = lis.insert({x, ct}).f;
        while (it2 != prev(lis.end())) {
            if (next(it2)->s <= ct) lis.erase(next(it2));
            else break;
        }
        ans[2] = max(ans[2], (ll) lis.size());
    }
    ans[2] = n - ans[2];

    ans[3] = n - 1;
    for (int p = pos[n], last = n; p >= 0; p--) {
        if (a[p] == last - 1) {
            last--;
            ans[3]--;
        }
    }

    for (auto &x : ans) cout << x << " ";
    cout << endl;
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