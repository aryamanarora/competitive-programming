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
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    multiset<int> st;
    multiset<int>::iterator it;
    st.clear();
    for(int i=0, j; i<n; i++) {
        cin >> j;
        st.insert(j);
        it=st.find(j);
        it++;
        if(it!=st.end()) st.erase(it);
    }
    cout<<st.size()<<endl;
    
    int m;
    cin >> n >> m;
    vector<pair<int, ii>> edges(m);
    for (auto &[w, u] : edges) cin >> u.f >> u.s >> w, u.f--, u.s--;

    int ans = 0;
    vector<map<int, int>> g(n);
    for (auto &[w, u] : edges) {
        if (g[u.f].size() == 0) {
            g[u.s][w] = max(g[u.s][w], 1);
            ans = max(ans, 1);
            continue;
        }
        auto it = g[u.f].lower_bound(w);
        if (it == g[u.f].begin()) {
            g[u.s][w] = max(g[u.s][w], 1);
            ans = max(ans, 1);
        }
        else {
            it--;
            g[u.s][w] = max(g[u.s][w], it->s + 1);
            ans = max(ans, it->s + 1);
        }
        cout << u.f << " " << u.s << " " << w << ": " << g[u.s][w] << endl;
    }

    cout << ans << endl;
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