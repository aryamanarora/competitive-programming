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

    int n;
    cin >> n;
    vii ct(n); map<int, int> l, r; int ok = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        stack<char> st;
        for (auto &c : s) {
            if (c == '(') {
                st.push(c);
                ct[i].f++;
            }
            else if (c == ')') {
                if (st.empty()) {
                    st.push(c);
                    ct[i].s++;
                }
                else if (st.top() == '(') {
                    st.pop();
                    ct[i].f--;
                }
                else {
                    st.push(c);
                    ct[i].s++;
                }
            }
        }
        if (ct[i].f == 0 and ct[i].s == 0) ok++;
        else if (ct[i].f == 0) l[ct[i].s]++;
        else if (ct[i].s == 0) r[ct[i].f]++;
    }

    int ans = ok / 2;
    // cout << ans << endl;
    for (auto &x : l) {
        ans += min(x.s, r[x.f]);
        // cout << x.f << " " << ans << endl;
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