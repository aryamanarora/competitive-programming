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

const int MAX = 5000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi a(n), colour(n, -1); for (auto &x : a) {cin >> x; x--;}

    vector<vector<bool>> used(MAX, vector<bool>(k, false));
    vector<bool> seen(k);
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < k; j++) {
            if (!seen[j]) {
                colour[i] = j;
                seen[j] = true;
                used[a[i]][j] = true;
                break;
            }
        }
        if (colour[i] == -1) {
            for (int j = 0; j < k; j++) {
                if (!used[a[i]][j]) {
                    colour[i] = j;
                    used[a[i]][j] = true;
                    break;
                }
            }
        }
        if (colour[i] == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (const auto &x : seen) {
        if (!x) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (auto &x : colour) cout << x + 1 << " ";
    cout << endl;
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