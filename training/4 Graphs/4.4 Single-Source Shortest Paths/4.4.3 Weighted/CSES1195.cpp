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

ll INF = numeric_limits<ll>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w, u--, v--;
        g[u].push_back({v, w});
    }

    vl dist1(n, INF), dist2(n, INF);
    set<pair<pair<int, ll>, int>> pq;
    pq.insert({{0, 0}, 0});
    while (!pq.empty()) {
        int u = pq.begin()->f.f, t = pq.begin()->s;
        ll d = pq.begin()->f.s;
        pq.erase(pq.begin());
        for (auto &v : g[u]) {
            if (t == 0) {
                if (d + v.s / 2 < dist2[v.f]) {
                    pq.erase({{v.f, dist2[v.f]}, 1});
                    dist2[v.f] = d + v.s / 2;
                    pq.insert({{v.f, dist2[v.f]}, 1});
                }
                if (d + v.s < dist1[v.f]) {
                    pq.erase({{v.f, dist1[v.f]}, 0});
                    dist1[v.f] = d + v.s;
                    pq.insert({{v.f, dist1[v.f]}, 0});
                }
            }
            else {
                if (d + v.s < dist2[v.f]) {
                    pq.erase({{v.f, dist2[v.f]}, 1});
                    dist2[v.f] = d + v.s;
                    pq.insert({{v.f, dist2[v.f]}, 1});
                }
            }
        }
    }

    cout << min(dist1[n - 1], dist2[n - 1]) << endl;
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