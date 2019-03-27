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

typedef tree<ii,null_type,less<ii>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
 
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
    
    int n, k;
    cin >> n >> k;
    vi a(n); for (auto &x : a) cin >> x;
    
    // compression
    si a_compress; for (auto &x : a) a_compress.insert(x);
    mii key;
    int temp = 1;
    for (auto &x : a_compress) {
        key[x] = temp;
        temp++;
    }
    
    fenwick_tree sum(a_compress.size() + 5);
    ordered_set s;
    ll cursum = 0;
    for (int i = 0; i < k - 1; i++) {
        sum.add(key[a[i]], a[i]);
        s.insert({a[i], i});
        cursum += a[i];
    }
    for (int i = k - 1; i < n; i++) {
        sum.add(key[a[i]], a[i]);
        s.insert({a[i], i});
        cursum += a[i];

        int median = s.find_by_order((k - 1) / 2)->f;
        ll ans = 0;
        ans += median * (s.order_of_key({median, -1})) - sum.sum(key[median] - 1);
        ans += (cursum - sum.sum(key[median])) - median * (k - s.order_of_key({median, n + 1}));
        cout << ans << " ";
        
        sum.add(key[a[i - k + 1]], -a[i - k + 1]);
        s.erase({a[i - k + 1], i - k + 1});
        cursum -= a[i - k + 1];
    }
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