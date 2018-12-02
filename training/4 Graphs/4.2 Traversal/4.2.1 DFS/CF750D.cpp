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

int n;
vi a,
   dirx { 0,  1,  1,  1,  0, -1, -1, -1 },
   diry { 1,  1,  0, -1, -1, -1,  0,  1 },
   l    { 7,  0,  1,  2,  3,  4,  5,  6 },
   r    { 1,  2,  3,  4,  5,  6,  7,  0 };
set<ii> ans;
set<vector<int>> memo;

void dfs(ii pos, int dir, int depth) {
    if (memo.count({pos.f, pos.s, dir, depth})) return;
    memo.insert({pos.f, pos.s, dir, depth});

    for (int i = 0; i < a[depth]; i++) {
        pos.f += dirx[dir];
        pos.s += diry[dir];
        ans.insert(pos);
        // cout << pos.f << " " << pos.s << endl;
    }

    depth++;
    if (depth == n) return;
    dfs(pos, l[dir], depth);
    dfs(pos, r[dir], depth);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    dfs({0, -1}, 0, 0);
    cout << ans.size() << endl;
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