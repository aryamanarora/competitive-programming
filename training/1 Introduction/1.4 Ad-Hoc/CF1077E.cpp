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

    int n, x;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    vii b(a.begin(), a.end());
    sort(b.begin(), b.end(), [](const auto &a, const auto &b) {
        return a.s > b.s;
    });

    ll last = b[0].s * 2, cur, ans = 0, ct = 0;
    for (auto [_, x] : b) {
        ct++;
        cur = min(last / 2, (ll) x);
        if (cur == 0) break;
        ans = max(ans, cur * (ll) (pow(2, ct) - 1));
        last = cur;
    }

    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/