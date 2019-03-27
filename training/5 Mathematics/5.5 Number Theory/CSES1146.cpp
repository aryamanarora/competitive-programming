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

map<ll, ll> dp;
ll calc(ll x) {
    if (dp.count(x)) return dp[x];
    ll val = pow(2, static_cast<ll>(log2(x)));
    if (val == x) val /= 2;
    return dp[x] = calc(val) + (x - val) + calc(x - val);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 0;
    dp[2] = 1;
 
    ll n;
    cin >> n;
    cout << calc(n + 1) << endl;
}
 
/*
USE LONG LONG!!!!
 
x      0 1 2 3 4 5 6 7  8  9
x+1    1 2 3 4 5 6 7 8  9  10
bitct  0 1 1 2 1 2 2 3  1  2
ans    0 1 2 4 5 7 9 12 13 15
 
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