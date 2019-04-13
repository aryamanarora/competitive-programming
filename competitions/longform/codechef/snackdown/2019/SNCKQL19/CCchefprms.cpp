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

const int MAX = 201;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> sieve(MAX, true);
    sieve[0] = false;
    sieve[1] = false;
    vi primes;
    for (int i = 2; i < MAX; i++) {
        if (sieve[i]) {
            for (int j = 2 * i; j < MAX; j += i) sieve[j] = false;
            primes.pb(i);
        }
    }

    set<int> semiprimes;
    for (auto &x : primes) {
        for (auto &y : primes) {
            if (x * y > MAX) break;
            if (x != y) semiprimes.insert(x * y);
        }
    }

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        bool found = false;
        for (auto &x : semiprimes) {
            if (semiprimes.count(n - x)) {
                found = true;
                break;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
}