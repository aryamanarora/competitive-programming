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

const int INF = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("visitfj.in");
    ofstream cout("visitfj.out");

    int n, t;
    cin >> n >> t;
    vi a(n * n);
    for (auto &x : a) cin >> x;

    // Dijkstra
    vi d(n * n, INF);
    vector<bool> u(n * n, false);
    d[0] = 0;

    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> q;
    q.push({0, {0, 0}});

    while (!q.empty()) {
        int v = q.top().s.f, w = q.top().f, ct = q.top().s.s;
        q.pop();
        if (w != d[v]) continue;

        cerr << v << " " << w << endl;

        if (ct == 2) {
            if (v / n > 0) {
                int r = v - n;
                if (d[v] + a[r] < d[r]) {
                    d[r] = d[v] + a[r];
                    q.push({d[r], {r, 0}});
                }
            }
            if (v % n > 0) {
                int r = v - 1;
                if (d[v] + a[r] < d[r]) {
                    d[r] = d[v] + a[r];
                    q.push({d[r], {r, 0}});
                }
            }
            if (v / n < n - 1) {
                int r = v + n;
                if (d[v] + a[r] < d[r]) {
                    d[r] = d[v] + a[r];
                    q.push({d[r], {r, 0}});
                }
            }
            if (v % n < n - 1) {
                int r = v + 1;
                if (d[v] + a[r] < d[r]) {
                    d[r] = d[v] + a[r];
                    q.push({d[r], {r, 0}});
                }
            }
        }
        else {
            if (v / n > 0) {
                int r = v - n;
                if (d[v] < d[r]) {
                    d[r] = d[v];
                    q.push({d[v], {r, ct + 1}});
                }
            }
            if (v % n > 0) {
                int r = v - 1;
                if (d[v] < d[r]) {
                    d[r] = d[v];
                    q.push({d[v], {r, ct + 1}});
                }
            }
            if (v / n < n - 1) {
                int r = v + n;
                if (d[v] < d[r]) {
                    d[r] = d[v];
                    q.push({d[v], {r, ct + 1}});
                }
            }
            if (v % n < n - 1) {
                int r = v + 1;
                if (d[v] < d[r]) {
                    d[r] = d[v];
                    q.push({d[v], {r, ct + 1}});
                }
            }
        }
    }

    cout << d[n - 1] << endl;
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