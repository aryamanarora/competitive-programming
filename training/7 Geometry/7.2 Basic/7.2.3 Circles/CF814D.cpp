#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef array<int, 3> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define M_PI 3.14159265358979323846264338327950288

struct circle {
    ll x, y, r;
    circle() : x(0), y(0), r(0) {};
    circle(ll a, ll b, ll c) : x(a), y(b), r(c) {};
    bool is_inside(const circle &a) const {
        double dist = sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
        if (dist + static_cast<double>(r) < static_cast<double>(a.r) + 1e-9) return true;
        return false;
    }
};

bool operator<(const circle &a, const circle &b) {
    return a.r < b.r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vii p(n, {-1, 0}); vector<circle> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i].is_inside(a[j])) {
                p[i] = {j, p[j].s + 1};
                break;
            }
        }
    }

    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        // cout << a[i].x << " " << a[i].y << " " << a[i].r << ": ";
        if (p[i].s % 2 or p[i].s == 0) {
            // cout << "added" << endl;
            ans += a[i].r * a[i].r;
        }
        else {
            // cout << "subtracted" << endl;
            ans -= a[i].r * a[i].r;
        }
    }
    cout << fixed << setprecision(10) << static_cast<double>(ans) * M_PI << endl;
}

/*
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