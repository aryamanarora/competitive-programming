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
 
mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    cin >> s;
    deque<int> a[4];
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') a[0].push_back(i);
        else if (s[i] == 'C') a[1].push_back(i);
        else if (s[i] == 'G') a[2].push_back(i);
        else a[3].push_back(i);
    }
 
    vi ans;
    auto print = [&]() {
        for (auto &x : ans) {
            if (x == 0) cout << 'A';
            else if (x == 1) cout << 'C';
            else if (x == 2) cout << 'G';
            else cout << 'T';
        }
        cout << '\n';
    };
    
    while (true) {
        int min = 0;
        for (int i = 0; i < 4; i++) {
            if (a[i].empty()) {
                ans.push_back(i);
                print();
                return 0;
            }
            else if (a[i].front() > a[min].front()) min = i;
        }
        ans.push_back(min);
        int pos = a[min].front();
        for (int i = 0; i < 4; i++) {
            while (a[i].front() <= pos) {
                a[i].pop_front();
                if (a[i].empty()) break;
            }
        }
    }
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
