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

map<char, ii> dir = {
    {'U', {0, 1}},
    {'R', {1, 0}},
    {'D', {0, -1}},
    {'L', {-1, 0}}
};

template<typename T, typename S>
void operator+=(pair<T, S> &x, const pair<T, S> &y) {
    x.f += y.f;
    x.s += y.s;
}

template<typename T, typename S>
pair<T, S>& operator+(const pair<T, S> &x, const pair<T, S> &y) {
    return mp(x.f + y.f, x.s + y.s);
}

ll dist(pair<ll, ll> &x, pair<ll, ll> &y) {
    return (abs(x.f - y.f) + abs(x.s - y.s));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<ll, ll> a, b; int n; string s;
    cin >> a.f >> a.s >> b.f >> b.s >> n >> s;

    vector<pair<ll, ll>> prefixsum(n);
    for (int i = 0; i < n; i++) {
        prefixsum[i] = dir[s[i]];
        if (i > 0) prefixsum[i] += prefixsum[i - 1];
    }

    auto check = [&](ll val) {
        pair<ll, ll> pos = a;
        pos.f += (val / n) * prefixsum[n - 1].f;
        pos.s += (val / n) * prefixsum[n - 1].s;
        if (val % n != 0) pos += prefixsum[val % n - 1];
        return (dist(pos, b) <= val);
    };

    ll lo = 0, hi = 1e16;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) hi = mid - 1;
        else lo = mid + 1;
    }

    cout << (lo >= 1e16 ? -1 : lo) << endl;
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