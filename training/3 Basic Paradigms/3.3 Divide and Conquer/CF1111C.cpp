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

    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    vi c(k); for (auto &x : c) cin >> x, x--;
    sort(c.begin(), c.end());

    int t;
    function<ll(int, int, vi::iterator, vi::iterator)> solve = [&](int l, int r, vi::iterator lit, vi::iterator rit) {
        if (l + 1 == r) {
            ll res = (lit == rit ? a : b * distance(lit, rit) * (r - l));
            // cout << l << " " << r << " " << distance(c.begin(), lit) << " " << distance(c.begin(), rit) << ": " << res << endl;
            return res;
        }
        int mid = (l + r) / 2;
        vi::iterator mit = lower_bound(c.begin(), c.end(), mid);
        if (lit == rit) return a;
        ll res = min(
            b * distance(lit, rit) * (r - l),
            solve(l, mid, lit, mit) + solve(mid, r, mit, rit)
        );
        // cout << l << " " << r << " " << distance(c.begin(), lit) << " " << distance(c.begin(), rit) << ": " << res << endl;
        return res;
    };

    cout << solve(0, pow(2, n), c.begin(), c.end()) << endl;
}

/*
0 1 2 3 4 5 6 7
[              )
[      )[      )
[  )[  )[  )[  )
2 1 2 1 1 1 1 1
0   2
*/