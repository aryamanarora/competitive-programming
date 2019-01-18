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

int mini(vi &x) {
    int res = x[0];
    for (int i = 1; i < x.size(); i++) res = min(res, x[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> a(n); for (auto &x : a) cin >> x;

    int at_old = 0, ag_old = 0, ac_old = 0, ta_old = 0, tg_old = 0, tc_old = 0, ca_old = 0, ct_old = 0, cg_old = 0, ga_old = 0, gt_old = 0, gc_old = 0;
    int at = 0, ag = 0, ac = 0, ta = 0, tg = 0, tc = 0, ca = 0, ct = 0, cg = 0, ga = 0, gt = 0, gc = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j % 2 == 0) {
                if (a[i][j] != 'a') at++, ag++, ac++;
                if (a[i][j] != 't') ta++, tg++, tc++;
                if (a[i][j] != 'c') ca++, cg++, ct++;
                if (a[i][j] != 'g') ga++, gt++, gc++;
            }
            else {
                if (a[i][j] != 'a') ta++, ga++, ca++;
                if (a[i][j] != 't') at++, gt++, ct++;
                if (a[i][j] != 'c') ac++, gc++, tc++;
                if (a[i][j] != 'g') ag++, tg++, cg++;
            }
        }
        at_old += min(cg, gc);
        ag_old += min(tc, ct);
        ac_old += min(gt, tg);
        ta_old += min(cg, gc);
        tg_old += min(ac, ca);
        tc_old += min(ag, ga);
        ca_old += min(tg, gt);
        ct_old += min(ag, ga);
        cg_old += min(at, ta);
        ga_old += min(tc, ct);
        gt_old += min(ac, ca);
        gc_old += min(at, ta);
    }

    vi b = {at_old, ag_old, ac_old, ta_old, tg_old, tc_old, ca_old, ct_old, cg_old, ga_old, gt_old, gc_old};
    cout << mini(b) << endl;
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