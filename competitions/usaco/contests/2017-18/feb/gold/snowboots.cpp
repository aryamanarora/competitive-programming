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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");
    
    int n, b;
    cin >> n >> b;
    vi a(n); vi left(n, -1), right(n, -1); map<int, vi> sorted;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i != 0) left[i] = i - 1;
        if (i != n - 1) right[i] = i + 1;
        sorted[a[i]].pb(i);
    }

    vii boots;
    for (int i = 0, s, d; i < b; i++) {
        cin >> s >> d;
        boots.pb({s, d});
    }
    
    vi ans(n, INF);
    int maxi = 1;
    for (int dist = 1; dist < n - 1; dist++) {
        while (maxi < dist) {
            int rem = sorted.rbegin()->s.back();
            sorted.rbegin()->s.pop_back();
            if (sorted.rbegin()->s.size() == 0) sorted.erase(prev(sorted.end()));
            left[right[rem]] = left[rem];
            right[left[rem]] = right[rem];
            maxi = max(maxi, right[rem] - left[rem]);
        }
        if (maxi > dist or sorted.size() == 0) ans[dist] = ans[dist - 1];
        else ans[dist] = sorted.rbegin()->f;
    }
    ans[n - 1] = 0;

    for (auto &x : ans) cerr << x << endl;

    for (auto &x : boots) {
        if (ans[x.s] <= x.f) cout << 1 << endl;
        else cout << 0 << endl;
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