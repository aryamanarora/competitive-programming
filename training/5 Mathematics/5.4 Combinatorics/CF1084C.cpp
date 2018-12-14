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
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

const ll MOD = (ll) 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    ll ans = 1;
    int ct = 0;
    for (auto c : s) {
        if (c == 'a') ct++;
        else if (c == 'b' and ct != 0) {
            ans *= (ct + 1);
            ans %= MOD;
            ct = 0;
        }
    }
    ans *= (ct + 1);
    ans %= MOD;
    cout << (ans + MOD - 1) % MOD << endl;
}

/*
USE LONG LONG!!!!
*/