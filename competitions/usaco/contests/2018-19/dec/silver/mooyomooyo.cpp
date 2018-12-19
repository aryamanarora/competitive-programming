#include <bits/stdc++.h>
#include <stdlib.h>

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

struct disjoint_set {
    int n, sets;
    vi parent, sz;

    disjoint_set(int N) : n(N), sets(0), parent(N), sz(N, 1) {
        for (int i = 0; i < N; i++) make_set(i);
    }
    void make_set(int v) {
        parent[v] = v;
        sets++;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    bool make_union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (b != a) {
            parent[b] = a;
            sets--;
            sz[a] += sz[b];
            sz[b] = 0;
            return false;
        }
        return true;
    }
};

bool cmp(int a, int b) {
    return static_cast<bool>(a) < static_cast<bool>(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("mooyomooyo.in");
    ofstream cout("mooyomooyo.out");

    int n, k;
    cin >> n >> k;

    vector<vi> board(10, vi(n));
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c;
            board[j][i] = (c - '0');
        }
    }

    bool changed;
    do {
        disjoint_set dsu(n * 10);
        changed = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (i < n - 1) {
                    if (board[j][i] == board[j][i + 1]) dsu.make_union(i * 10 + j, (i + 1) * 10 + j);
                }
                if (i > 0) {
                    if (board[j][i] == board[j][i - 1]) dsu.make_union(i * 10 + j, (i - 1) * 10 + j);
                }
                if (j < 9) {
                    if (board[j][i] == board[j + 1][i]) dsu.make_union(i * 10 + j, i * 10 + j + 1);
                }
                if (j > 0) {
                    if (board[j][i] == board[j - 1][i]) dsu.make_union(i * 10 + j, i * 10 + j - 1);
                }
            }
        }

        set<int> ch;
        for (int i = 0; i < n * 10; i++) {
            // cerr << dsu.sz[i] << " ";
            if (dsu.sz[i] >= k and board[i % 10][i / 10] != 0) {
                changed = true;
                ch.insert(i);
            }
        }
        // cerr << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (ch.count(dsu.find_set(i * 10 + j))) board[j][i] = 0;
            }
        }

        for (int j = 0; j < 10; j++) {
            stable_sort(board[j].begin(), board[j].end(), cmp);
        }

        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                cerr << board[j][i];
            }
            cerr << endl;
        }
        */
    } while (changed);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[j][i];
        }
        cout << endl;
    }
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