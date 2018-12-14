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

    int x, y, n;
    cin >> x >> y >> n;
    vector<pair<ii, double>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f.f >> a[i].f.s >> a[i].s;
    }
    sort(a.begin(), a.end());

    double ans = (y - (a.size() == 0 ? 0.0 : a.back().f.s)); int last = 0;
    for (auto x : a) {
        ans += (x.f.f - last);
        ans += (x.f.s - x.f.f) * x.s;
        last = x.f.s;
    }
    ans = static_cast<double>(x) / ans;
    cout << fixed << setprecision(11) << ans << endl;
}

/*
USE LONG LONG!!!!
*/