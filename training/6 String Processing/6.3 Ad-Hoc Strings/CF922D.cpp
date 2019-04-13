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

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count() << 1);

const int INF = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<string, int>> a(n);
    vl score(n), s(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f;
        a[i].s = i;
        ll ct = 0;
        for (auto &y : a[i].f) {
            if (y == 's') ct++;
            else score[i] += ct;
        }
        s[i] = ct;
        h[i] = a[i].f.length() - ct;
    }
    sort(a.begin(), a.end(), [&](const auto &a, const auto &b) {
        ll sa = score[a.s] + h[b.s] * s[a.s] + score[b.s];
        ll sb = score[b.s] + h[a.s] * s[b.s] + score[a.s];
        // cout << a.f << " " << b.f << ": " << sa << " " << sb << endl;
        return sb < sa;
    });

    ll ans = 0;
    ll ct = 0;
    for (auto &x : a) {
        for (auto &y : x.f) {
            if (y == 's') ct++;
            else ans += ct;
        }
    }

    cout << ans << endl;
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