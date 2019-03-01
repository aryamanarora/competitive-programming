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

const int MAX = 5000001;

int main() {
    vl ct(MAX);
    vl val(MAX);
    iota(val.begin(), val.end(), 0LL);
    for (int i = 2; i * i <= MAX; i++) {
        if (ct[i] != 0) continue;
        for (int j = i; j < MAX; j += i) {
            while (val[j] % i == 0) val[j] /= i, ct[j]++;
        }
    }
    for (int i = 0; i < 100; i++) cout << ct[i] << endl;
    for (int i = 1; i < MAX; i++) ct[i] += ct[i - 1];

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << ct[a] - ct[b - 1] << endl;
    }
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