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

const ll MOD = 1e9 + 7;

ll addmod(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}
ll mulmod(ll a, ll b) {
    ll res = 0;
    a %= MOD;
    b %= MOD;
    if (b > a) swap(a, b);
    while (b > 0) {
        if (b % 2) res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
  	int n, a, b;
    cin >> n >> a >> b;
    n = pow(2, n);

    vi ans;
    ans.pb(a);
    vector<bool> used(n, false);
    used[a] = true;
    used[b] = true;
    for (int i = 1; i < n - 1; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (!used[ans.back() xor (1 << j)]) {
                used[ans.back() xor (1 << j)] = true;
                ans.pb(ans.back() xor (1 << j));
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (__builtin_popcount(b xor ans.back()) == 1) ans.pb(b);
    else {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    for (int i = 1; i < pow(2, n); i++) cout << (ans[i] xor ans[i - 1]) << " ";
    cout << endl;
}

/*
1 3 1 2 3 2 4
1   1
  3     3
      2   2

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