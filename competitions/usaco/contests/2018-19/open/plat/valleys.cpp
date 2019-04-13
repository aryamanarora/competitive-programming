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

struct disjoint_set {
    int n;
    vector<vii> parent;
    vector<vi> size;
    vector<vector<bool>> exist;

    disjoint_set(int N) : n(N), size(N, vi(N)), parent(N, vii(N)), exist(N, vector<bool>(N)) {
    }
    void make_set(int x, int y) {
        parent[x][y] = {x, y};
        size[x][y] = 1;
    }
    ii find_set(int x, int y) {
        if (mp(x, y) == parent[x][y]) return {x, y};
        return parent[x][y] = find_set(parent[x][y].first, parent[x][y].second);
    }
    void make_union(int x1, int y1, int x2, int y2) {
        tie(x1, y1) = find_set(x1, y1);
        tie(x2, y2) = find_set(x2, y2);
        if (tie(x1, y1) != tie(x2, y2)) {
            if (size[x1][y1] < size[x2][y2]) {
                swap(x1, x2);
                swap(y1, y2);
            }
            parent[x2][y2] = {x1, y1};
            size[x1][y1] += size[x2][y2];
            size[x2][y2] = 0;
        }
    }
};

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("valleys.in");
    ofstream cout("valleys.out");

    int n;
    cin >> n;
    vector<vi> a(n, vi(n));
    vector<pair<int, ii>> ord;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            ord.push_back({a[i][j], {i, j}});
        }
    }

    sort(ord.begin(), ord.end());
    disjoint_set dsu(n);

    ll ans = 0;
    for (auto &x : ord) {
        sii comp;
        int ct = 0;
        dsu.make_set(x.s.f, x.s.s);
        dsu.exist[x.s.f][x.s.s] = true;
        for (int i = 0; i < 4; i++) {
            int j = x.s.f + dx[i], k = x.s.s + dy[i];
            if (j < 0 or j >= n or k < 0 or k >= n) continue;
            if (!dsu.exist[j][k]) continue;
            else {
                comp.insert({dsu.find_set(j, k)});
                dsu.make_union(x.s.f, x.s.s, j, k);
            }
        }
        ii set = dsu.find_set(x.s.f, x.s.s);
        ans += dsu.size[set.f][set.s];
        
        /*
        cerr << ans << ": " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cerr << dsu.exist[i][j];
            cerr << endl;
        }
        cerr << endl;
        */
    }

    sort(ord.rbegin(), ord.rend());
    disjoint_set dsu2(n);
    vector<vector<bool>> work(n, vector<bool>(n));
    ll cur = n * n;
    for (auto &x : ord) {
        dsu2.make_set(x.s.f, x.s.s);
        dsu2.exist[x.s.f][x.s.s] = true;
        work[x.s.f][x.s.s] = true;
        cur--;
        for (int i = 0; i < 4; i++) {
            int j = x.s.f + dx[i], k = x.s.s + dy[i];
            if (j < 0 or j >= n or k < 0 or k >= n) continue;
            if (!dsu2.exist[j][k]) continue;
            else dsu2.make_union(x.s.f, x.s.s, j, k);
            work[x.s.f][x.s.s] = (work[x.s.f][x.s.s] and work[j][k]); 
        }
        ii set = dsu2.find_set(x.s.f, x.s.s);
        if (!work[x.s.f][x.s.s]) work[set.f][set.s] = false;
        if (x.s.f != 0 and x.s.f != n - 1 and x.s.s != 0 and x.s.s != n - 1 and work[set.f][set.s]) {
            ans -= cur;
        }
        else work[set.f][set.s] = false;
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