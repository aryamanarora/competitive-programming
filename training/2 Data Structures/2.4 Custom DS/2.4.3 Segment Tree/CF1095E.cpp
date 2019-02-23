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

struct segment_tree {
    int n;
    vi l, r;

    segment_tree(int N, string &s) : n(4 * N), l(4 * N), r(4 * N) {
        build(s, 1, 0, N - 1);
    };

    void build(string &a, int v, int tl, int tr) {
        if (tl == tr) {
            if (a[tl] == '(') l[v] = 1;
            else r[v] = 1;
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            int matched = min(l[v * 2], r[v * 2 + 1]);
            l[v] = l[v * 2] - matched + l[v * 2 + 1];
            r[v] = r[v * 2] + r[v * 2 + 1] - matched;
        }
    };

    void flip(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            swap(l[v], r[v]);
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) flip(v * 2, tl, tm, pos);
            else flip(v * 2 + 1, tm + 1, tr, pos);

            int matched = min(l[v * 2], r[v * 2 + 1]);
            l[v] = l[v * 2] - matched + l[v * 2 + 1];
            r[v] = r[v * 2] + r[v * 2 + 1] - matched;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n >> s;

    segment_tree segtree(n, s);

    /*
    for (auto &x : segtree.l) cout << x << " ";
    cout << endl;
    for (auto &x : segtree.r) cout << x << " ";
    cout << endl;
    */
   
    int ans = 0;
    for (int i = 0; i < n; i++) {
        segtree.flip(1, 0, n - 1, i);
        ans += (segtree.l[1] == 0 and segtree.r[1] == 0);
        segtree.flip(1, 0, n - 1, i);
    }

    cout << ans << endl;
}

/*
(((())
    ((
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