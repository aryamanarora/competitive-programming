#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
typedef tree<ii,null_type,less<ii>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

struct query {
    int a, b, c, id;
};

bool operator<(const query &a, const query &b) {
    return (a.a < b.a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<bool> used(n, true);

    sii a;
    ordered_set b, c;
    vi bb(n), cc(n);
    for (int i = 0, s, t; i < n; i++) {
        cin >> s >> t;
        a.insert({s, i});
        b.insert({t, i});
        c.insert({s + t, i});
        bb[i] = t;
        cc[i] = s + t;
    }

    vi ans(q);
    vector<query> qs(q);
    int ct = 0;
    for (auto &x : qs) {
        cin >> x.a >> x.b >> x.c;
        x.id = ct++;
    }
    sort(qs.begin(), qs.end());

    ct = n;
    for (auto &x : qs) {
        while (a.begin()->f < x.a) {
            ct--;
            b.erase({bb[a.begin()->s], a.begin()->s});
            c.erase({cc[a.begin()->s], a.begin()->s});
            a.erase(a.begin());
        }

        int minb = max(x.b, x.c - x.a);
        int anss = b.order_of_key({minb, -1});
        ans[x.id] = ct - anss;
    }

    for (auto &x : ans) cout << x << '\n';
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