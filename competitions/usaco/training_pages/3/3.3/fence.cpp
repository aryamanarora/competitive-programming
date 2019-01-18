/*
ID: aryaman4
TASK: fence
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("fence.in");
    ofstream cout("fence.out");

    int e; int n = 0;
    cin >> e;
    vector<multiset<int>> g;
    for (int i = 0, u, v; i < e; i++) {
        cin >> u >> v;
        if (max(u, v) + 1 > n) {
            n = max(u, v) + 1;
            g.resize(n + 1);
        }
        g[u].insert(v);
        g[v].insert(u);
    }

    stack<int> st;
    vi res;
    int start = 1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() % 2) {
            start = i;
            break;
        }
    }
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        if (g[u].size() == 0) {
            res.pb(u);
            st.pop();
        } 
        else {
            int v = *g[u].begin();
            g[u].erase(g[u].find(v));
            g[v].erase(g[v].find(u));
            st.push(v);
        }
    }

    reverse(res.begin(), res.end());
    for (auto &x : res) cout << x << endl;
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