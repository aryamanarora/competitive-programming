/*
ID: aryaman4
TASK: msquare
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

struct disjoint_set {
    int n, sets;
    vi parent, size;

    disjoint_set(int N) : n(N), size(N), parent(N), sets(0) {
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
        sets++;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (b != a) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
            sets--;
        }
    }
};

int dist(vi &a, vi &b) {
    int res = 0;
    for (int i = 0; i < 4; i++) res += abs(a[i] - b[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("25.in");

    vector<vi> a;
    string s;
    while (cin >> s) {
        stringstream ss(s);
        int i; vi cur;
        while (ss >> i) {
            cur.pb(i);
            if (ss.peek() == ',')
                ss.ignore();
        }
        a.pb(cur);
    }

    int n = a.size();
    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(a[i], a[j]) <= 3) {
                dsu.make_union(i, j);
            }
        }
    }

    cout << dsu.sets << endl;
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