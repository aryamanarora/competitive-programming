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

    ifstream cin("sort.in");
    ofstream cout("sort.out");

    int n;
    cin >> n;
    vi a(n); for (auto &x : a) cin >> x;
    vi a_sorted = a; sort(a_sorted.begin(), a_sorted.end());

    fenwick_tree ft(a_sorted[n - 1]);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ft.add(a[i], 1);
        ans = max(ans, i + 1 - ft.sum(a_sorted[i]));
    }
    cout << ans << endl;
}

/*
1 8 5 3 2
1 2 3 5 8
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