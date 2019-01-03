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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("msquare.in");
    ofstream cout("msquare.out");

    vi a(8), start = {1, 2, 3, 4, 8, 7, 6, 5};
    for (auto &x : a) cin >> x;
    swap(a[7], a[4]);
    swap(a[6], a[5]);
    map<vi, pair<vi, ii>> parent;
    queue<pair<vi, ii>> bfs;
    bfs.push({start, {0, -1}});
    while (!bfs.empty()) {
        pair<vi, ii> cur = bfs.front();
        
        bfs.pop(); string s;
        if (cur.f == a) {
            cout << cur.s.f << endl;
            while (cur.s.s != -1) {
                s.pb(cur.s.s + 'A');
                cur = parent[cur.f];
            }
            reverse(s.begin(), s.end());
            cout << s << endl;
            break;
        }

        vi A = {cur.f[4], cur.f[5], cur.f[6], cur.f[7], cur.f[0], cur.f[1], cur.f[2], cur.f[3]};
        if (!parent.count(A)) {
            bfs.push({A, {cur.s.f + 1, 0}});
            parent[A] = cur;
        }
        A = {cur.f[3], cur.f[0], cur.f[1], cur.f[2], cur.f[7], cur.f[4], cur.f[5], cur.f[6]};
        if (!parent.count(A)) {
            bfs.push({A, {cur.s.f + 1, 1}});
            parent[A] = cur;
        }
        A = {cur.f[0], cur.f[5], cur.f[1], cur.f[3], cur.f[4], cur.f[6], cur.f[2], cur.f[7]};
        if (!parent.count(A)) {
            bfs.push({A, {cur.s.f + 1, 2}});
            parent[A] = cur;
        }
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