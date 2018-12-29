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
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

double sinh(double x) {
    return (exp(x) - exp(-1 * x)) / 2;
}

double cosh(double x) {
    return (exp(x) + exp(-1 * x)) / 2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double d, s;
    cin >> d >> s;

    if (s == 0.0) {
        cout << fixed << setprecision(10) << d << endl;
        return 0;
    }

    double lo = 0.0, hi = 1000000000.0, a;
    while (abs(hi - lo) > 1e-10) {
        a = (lo + hi) / 2;
        double ss = a * cosh(d / (2 * a)) - a - s;
        if (ss > 0) lo = a;
        else hi = a;
    }

    cout << fixed << setprecision(10) << 2 * a * sinh(d / (2 * a)) << endl;
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