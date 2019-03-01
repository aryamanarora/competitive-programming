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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> a(n); for (auto &x : a) cin >> x;
    vi b(m, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '<') b[j]++;
        }
    }

    vi aa(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '>') aa[i] = max(aa[i], b[j] + 1);
            else if (a[i][j] == '<') aa[i] = min(aa[i], b[j] - 1);
            else aa[i] = b[j];
        }
    }

    bool works = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '>' and aa[i] <= b[j]) works = false;
            if (a[i][j] == '<' and aa[i] >= b[j]) works = false;
            if (a[i][j] == '=' and aa[i] != b[j]) works = false;
            // cout << a[i][j] << ": " << aa[i] << " " << b[j] << endl;
        }
    }

    cout << (works ? "Yes" : "No") << endl;
    if (works) {
        si vals;
        for (auto &x : aa) vals.insert(x);
        for (auto &x : b) vals.insert(x);
        mii key;
        int ct = 1;
        for (auto &x : vals) key[x] = (ct++);
        for (auto &x : aa) cout << key[x] << " ";
        cout << endl;
        for (auto &x : b) cout << key[x] << " ";
        cout << endl;
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