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

ld dist(pair<ld, ld> a, pair<ld, ld> b) {
    return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d1, d2;
    cin >> n >> d1 >> d2;
    d1 *= d1, d2 *= d2;
    int ans = 0; pair<ld, ld> lasta, lastb;
    bool lasttalk = false, talked = false;
    for (int i = 0; i < n; i++) {
        pair<ld, ld> a, b;
        cin >> a.f >> a.s >> b.f >> b.s;
        if (i == 0) {
            lasta = a, lastb = b;
            continue;
        }
        for (ld j = 0.0; j < 1.0; j += 0.01) {
            ld d = dist({lasta.f + (a.f - lasta.f) * j, lasta.s + (a.s - lasta.s) * j}, {lastb.f + (b.f - lastb.f) * j, lastb.s + (b.s - lastb.s) * j});
            if (d <= d1) {
                if (!talked) {
                    talked = true;
                    ans++;
                    // cout << "first time: " << sqrt(d) << endl;
                }
                else if (lasttalk) {
                    lasttalk = false;
                    ans++;
                    // cout << "long wait: " << sqrt(d) << endl;
                }
            }
            else if (d > d2 and talked) {
                // cout << "d > d2: " << sqrt(d) << endl;
                lasttalk = true;
            }
        }
        lasta = a, lastb = b;
    }

    cout << ans << endl;
}

/*
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