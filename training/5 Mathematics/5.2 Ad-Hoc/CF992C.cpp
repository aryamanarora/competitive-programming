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

const ll MOD = 2 * (1e9 + 7);

ll modpow(ll x, ll y) 
{ 
    ll res = 1;      // Initialize result 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % MOD; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % MOD;   
    } 
    return res; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, k;
    cin >> x >> k;

    if (x == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll maxi = ((x % MOD) * modpow(2, k + 1)) % MOD;
    ll mini = (((maxi - (modpow(2, k) - 1) * 2) % MOD) + MOD) % MOD;

    cout << ((maxi + mini) / 2 + (MOD / 2)) % (MOD / 2) << endl;
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

/*
2
0: 4
   3 4
1: 6 8 
   5 6 7 8
2: 10 12 14 16
   9 10 11 12 13 14 15 16
3: 18

1
0: 2
   1 2
1: 2 4
   1 2 3 4
2: 2 4 6 8
*/