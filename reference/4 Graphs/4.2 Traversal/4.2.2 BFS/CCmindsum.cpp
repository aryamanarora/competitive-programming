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

ll digitsum(ll x) {
    ll ans = 0;
    while (x > 0) {
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    ll n, d;
    while (t--) {
        cin >> n >> d;
        queue<pair<ll, pair<int, int>>> q;
        pair<ll, pair<int, int>> ans = mp(n, mp(0, 0));
        q.push(ans);
        while (!q.empty()) {
            pair<ll, pair<int, int>> cur = q.front();
            q.pop();
            ans = min(ans, cur);
            if (cur.f > 9) q.push(mp(digitsum(cur.f), mp(cur.s.f + 1, cur.s.s)));
            if (cur.s.s < 9) q.push(mp(cur.f + d, mp(cur.s.f + 1, cur.s.s + 1)));
        }
        cout << ans.f << " " << ans.s.f << endl;
    }
}