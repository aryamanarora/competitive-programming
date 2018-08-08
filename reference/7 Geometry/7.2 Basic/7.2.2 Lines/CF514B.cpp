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

    int n;
    cin >> n;

    ii pos;
    cin >> pos.f >> pos.s;

    vii t;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        t.pb(mp(x, y));
    }

    int ans = 0;
    for (int i = 0; i < t.size();) {
        for (int j = 1; j < t.size();) {
            if (pos.f * (t[i].s - t[j].s) + t[i].f * (t[j].s - pos.s) + t[j].f * (pos.s - t[i].s) == 0) t.erase(t.begin() + j);
            else j++;
        }
        t.erase(t.begin() + i);
        ans++;
    }

    cout << ans << endl;
}