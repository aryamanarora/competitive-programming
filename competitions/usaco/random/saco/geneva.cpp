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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a) cin >> x;
    stack<int> branch;
    int need = 1;
    while (true) {
        if (need == n + 1) {
            cout << "Y" << endl;
            break;
        }
        if (!branch.empty()) {
            if (branch.top() == need) {
                branch.pop();
                need++;
                continue;
            }
            else if (!a.empty()) {
                if (a.back() == need) {
                    a.pop_back();
                    need++;
                    continue;
                }
                else {
                    branch.push(a.back());
                    a.pop_back();
                    continue;
                }
            }
            else {
                cout << "N" << endl;
                break;
            }
        }
        else if (!a.empty()) {
            if (a.back() == need) {
                a.pop_back();
                need++;
                continue;
            }
            else {
                branch.push(a.back());
                a.pop_back();
                continue;
            }
        }
        else {
            cout << "N" << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
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