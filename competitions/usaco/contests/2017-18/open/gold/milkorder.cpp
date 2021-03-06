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

    ifstream cin("milkorder.in");
    ofstream cout("milkorder.out");

    int n, m;
    cin >> n >> m;
    vector<vii> g(n);
    for (int i = 0; i < m; i++) {
        int k, last = -1;
        cin >> k;
        for (int h = 0, j; h < k; h++) {
            cin >> j;
            j--;
            if (last != -1) g[last].pb({j, i});
            last = j;
        }
    }

    vi order;
    auto check = [&](int lim) {
        order.clear();
        vector<bool> vis(n, false);
        priority_queue<int, vi, greater<int>> pq;
        
        vi degree(n);
        for (int u = 0; u < n; u++) {
            for (auto &v : g[u]) if (v.s < lim) degree[v.f]++;
        }
        for (int i = 0; i < n; i++) if (degree[i] == 0) pq.push(i);

        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();
            order.pb(u + 1);
            vis[u] = true;
            for (auto &v : g[u]) {
                if (v.s < lim) {
                    if (vis[v.f]) return false;
                    degree[v.f]--;
                    if (degree[v.f] == 0) pq.push(v.f);
                }
            }
        }

        if (order.size() != n) return false;
        return true;
    };

    int lo = 1, hi = m;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    check(hi);
    
    cout << order[0];
    order.erase(order.begin());
    for (auto &x : order) cout << " " << x;
    cout << endl;
}

/*
1 8 5 3 2
1 2 3 5 8
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