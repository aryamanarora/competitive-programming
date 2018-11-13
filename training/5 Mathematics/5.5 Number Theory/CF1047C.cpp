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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, g = 0, maxn = 0;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (g == 0) g = a[i];
        else g = gcd(a[i], g);
        maxn = max(a[i], maxn);
    }
    maxn++;
    
    vi sieve(maxn, 0);
    sieve[1] = 1;
    for (int i = 2; i * i < maxn; i++) {
        if (sieve[i] == 0) {
            for (int j = i * i; j < maxn; j += i) sieve[j] = i;
        }
    }

    int ans = 0;
    map<int, int> ct;
    for (auto &x : a) {
        x /= g;
        int fac;
        while (x > 1) {
            fac = sieve[x];
            if (fac == 0) fac = x;
            ct[fac]++;
            ans = max(ct[fac], ans);
            while (x % fac == 0) x /= fac;
        }
    }
    
    cout << (ans == 0 ? -1 : n - ans) << endl;
}