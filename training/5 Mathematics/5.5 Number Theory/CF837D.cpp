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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vl a(n); vi twos(n, 0), fives(n, 0);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) {
            twos[i]++;
            a[i] /= 2;
        }
        while (a[i] % 5 == 0) {
            fives[i]++;
            a[i] /= 5;
        }
    }

    vii cur(k); int two = 0, five = 0;
    for (int i = 0; i < k; i++) {
        cur[i] = {twos[i], fives[i]};
        two += twos[i]; five += fives[i];
    }

    for (int i = k; i < n; i++) {
        // ???
    }
}

/*
15 16 3 25 9
5 2*2*2*2  5*5



USE LONG LONG!!!!

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