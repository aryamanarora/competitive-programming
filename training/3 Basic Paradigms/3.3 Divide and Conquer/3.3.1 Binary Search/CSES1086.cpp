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

unsigned long long cost(unsigned long long a) {
    unsigned long long res = 0;
    for (unsigned long long i = 1; i <= a; i *= 10) {
        if (a < i * 2) res += a - i + 1;
        else res += ((a / i) / 10 + (a - (a / i) / 10 ? 1 : 0)) * i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long n;
    cin >> n;
    
    unsigned long long lo = 1, hi = numeric_limits<ll>::max();
    while (lo <= hi) {
        unsigned long long mid = lo + (hi - lo) / 2;
        if (cost(mid) > n) hi = mid - 1;
        else lo = mid + 1;
    }

    cout << hi << endl;
}

/*
USE LONG LONG!!!!

1000000
9: 1
99: 20
999: 300
9999: 4000
99999: 50000
999999: 600000

99:
    9x: 10
     9: 10

999:
    9xx: 100
     9x: 10*10 = 100
      9: 100*1 = 100

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