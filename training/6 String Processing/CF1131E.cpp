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

const ll MAX = 1e9;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> a(n); for (auto &x : a) cin >> x;
    reverse(a.begin(), a.end());
    string s = a[0];
    pair<char, ll> start = {s[0], 0}, end = {s.back(), 0};
    for (auto &x : s) {
        if (x == s[0]) start.s++;
        else break;
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == s.back()) end.s++;
        else break;
    }

    ll len = s.length();
    ll ans = max(start.s, end.s);

    ll cur = 1;
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) cur++;
        else cur = 1;
        ans = max(ans, cur);
    }

    for (int i = 1; i < n; i++) {
        s = a[i];
        if (start.s == len) {
            ll run = start.s;
            bool t = true;
            for (auto &x : s) {
                if (x == start.f) run += 1 + len;
                else {
                    if (t) {
                        start.s = run;
                        t = false;
                    }
                    run = len;
                }
                ans = max(ans, run);
            }
            if (t) start.s = run;
            end.s = run;
            len = min(MAX, (ll) s.length() + ((ll) s.length() + 1) * len);
        }
        else {
            for (auto &x : s) {
                if (x == end.f and x == start.f) ans = max(ans, end.s + 1 + start.s);
                else if (x == end.f) ans = max(ans, end.s + 1);
                else if (x == start.f) ans = max(ans, start.s + 1);
            }
            len = min(MAX, (ll) s.length() + ((ll) s.length() + 1) * len);
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