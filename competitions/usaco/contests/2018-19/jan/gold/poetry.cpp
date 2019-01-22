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

const int MOD = 1000000007;

ll modpow(ll x, ll y) 
{ 
    int res = 1;      // Initialize result 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % MOD; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % MOD;   
    } 
    return res; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("poetry.in");
    ofstream cout("poetry.out");

    int n, m, k;
    cin >> n >> m >> k;
    vii words(n);
    for (auto &x : words) {
        cin >> x.f >> x.s;
        x.s--;
    }

    // coin change: find how many ways we can make a verse of k syllables for each rhyme scheme
    vi dp(k); mii ct;
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (auto &x : words) {
            if (i - x.f >= 0) {
                if (i == k) {
                    ct[x.s] += dp[i - x.f];
                    ct[x.s] %= MOD;
                }
                else {
                    dp[i] += dp[i - x.f];
                    dp[i] %= MOD;
                }
            }
        }
    }

    map<char, int> scheme;
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        scheme[c]++;
    }

    vi sc; // count of each letter in scheme
    vi ways; // ways to make k syllables ending with x
    for (auto &x : scheme) sc.pb(x.s);
    for (auto &x : ct) ways.pb(x.s);

    vector<vl> dp2(sc.size(), vl(ways.size()));
    ll lastsum = 0, newsum = 0;
    for (int i = 0; i < sc.size(); i++) {
        for (int j = 0; j < ways.size(); j++) {
            if (i == 0) dp2[i][j] = modpow(ways[j], sc[i]);
            else {
                dp2[i][j] += lastsum * modpow(ways[j], sc[i]);
                dp2[i][j] %= MOD;
            }
            newsum += dp2[i][j];
            newsum %= MOD;
        }
        lastsum = newsum;
        newsum = 0;
    }

    /*
    for (auto &x : dp2) {
        for (auto &y : x) cerr << y << " ";
        cerr << endl;
    }
    */

    ll ans = 0;
    for (int i = 0; i < ways.size(); i++) {
        ans += dp2[sc.size() - 1][i];
        ans %= MOD;
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

ABAB
1111
1212
2121
2222
*/