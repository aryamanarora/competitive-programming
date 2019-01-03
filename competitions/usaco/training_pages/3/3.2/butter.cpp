/*
ID: aryaman4
TASK: butter
LANG: C++14
*/

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

int n, p, c;

void dijkstra(int s, vi &d, vector<vii> &g, vl &total) {
    vector<bool> u(p, false);
    d[s] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});

    while (!q.empty()) {
        int v = q.top().s, w = q.top().f;
        q.pop();
        if (w != d[v]) continue;

        for (auto &child : g[v]) {
            if (d[v] + child.s < d[child.f]) {
                d[child.f] = d[v] + child.s;
                q.push({d[child.f], child.f});
            }
        }
    }

    for (int i = 0; i < p; i++) total[i] += d[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("butter.in");
    ofstream cout("butter.out");

    cin >> n >> p >> c;
    vi sources(n);
    for (auto &x : sources) {
        cin >> x;
        x--;
    }
    vector<vii> g(p);
    for (int i = 0, u, v, w; i < c; i++) {
        cin >> u >> v >> w;
        u--; v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    vl total(p, 0);
    for (auto &x : sources) {
        vi d(p, INF);
        dijkstra(x, d, g, total);
    }

    cout << *min_element(total.begin(), total.end()) << endl;
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