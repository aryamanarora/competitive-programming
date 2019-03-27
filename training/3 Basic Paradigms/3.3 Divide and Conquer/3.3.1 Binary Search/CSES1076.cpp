#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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

typedef tree<ii,null_type,less<ii>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi a(n); for (auto &x : a) cin >> x;
    ordered_set s;
    for (int i = 0; i < k - 1; i++) s.insert({a[i], i});
    for (int j = k - 1; j < n; j++) {
        s.insert({a[j], j});
        cout << s.find_by_order((k - 1) / 2)->f << ' ';
        s.erase({a[j - k + 1], j - k + 1});
    }
    cout << endl;
}
 
/*
USE LONG LONG!!!!
 
:pray: :fishy15:
:pray: :summitosity:
:pray: :prodakcin:
 
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