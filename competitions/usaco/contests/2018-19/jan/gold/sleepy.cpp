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

    ifstream cin("sleepy.in");
    ofstream cout("sleepy.out");

    int n;
    cin >> n;
    vi a(n), pos(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    vii seq;
    function<bool(const int, const int)> cmp = [&](const int &a, const int &b) {
        if (a < b) seq.pb({a, b});
        return a < b;
    };
    sort(a.begin(), a.end(), cmp);

    vi ans;
    for (auto &x : seq) {
        for (int i = 0; i < min(pos[x.f], pos[x.s]); i++) ans.pb(min(pos[x.f], pos[x.s]));
        ans.pb(max(pos[x.f], pos[x.s]));
        swap(pos[x.f], pos[x.s]);
    }
    cout << ans.size() << endl;
    for (auto &x : ans) cout << x << " ";
    cout << endl;
}

/*
1 2 3

1 3 2
1 2

2 1 3
1

2 3 1
2 2

3 1 2
2

3 2 1
2 1


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