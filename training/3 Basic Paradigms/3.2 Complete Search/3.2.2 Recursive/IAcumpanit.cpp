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

vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

ll a, b;
set<ll> ans;

void backtrack(ll cur, int idx, int sum, int ct) {
    if (sum == ct and a < cur and cur < b) ans.insert(cur);
    if (cur * primes[idx] < b and idx != -1) backtrack(cur * primes[idx], idx, sum, ct + 1);
    for (int i = idx + 1; i < static_cast<int>(primes.size()); i++) {
        if (cur * primes[i] > b) break;
        backtrack(cur * primes[i], i, sum + primes[i], ct + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("cumpanit.in");
    ofstream cout("cumpanit.out");
    
    cin >> a >> b;
    backtrack(1LL, -1, 0, 0);
    for (auto x : ans) cout << x << '\n';
}