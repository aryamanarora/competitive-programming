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

const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, y;
    cin >> n >> x >> y;
    vii a(n);
    for (int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
    sort(a.begin(), a.end());
    ll ans = 0;
    multiset<ii> tvs;
    for (auto [l, r] : a) {
        auto tv = tvs.lower_bound({l, 0});
        if (tv == tvs.begin()) {
            tvs.insert({r, l});
            ans += x;
            ans %= MOD;
            continue;
        }
        tv--;
        if ((l - tv->f) * y > x) {
            tvs.insert({r, l});
            ans += x;
            ans %= MOD;
        }
        else {
            tvs.insert({r, tv->s});
            tvs.erase(tv);
        }
        /*
        for (auto x : tvs) cout << x.s << " " << x.f << ", ";
        cout << endl;
        cout << "------" << endl;
        */
    }
    // cout << "------" << endl;
    for (auto [r, l] : tvs) {
        // cout << l << " " << r << endl;
        ans += y * (r - l);
        ans %= MOD;
    }
    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/