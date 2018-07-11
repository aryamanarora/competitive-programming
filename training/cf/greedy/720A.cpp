#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ll n, m;
    cin >> n >> m;
    int k_l = 0, l_l = 0;
    cin >> k_l;
    vi k(k_l);
    for (int i = 0; i < k_l; i++) cin >> k[i];
    cin >> l_l;
    vi l(l_l);
    for (int i = 0; i < l_l; i++) cin >> l[i];

    sort(k.rbegin(), k.rend());
    sort(l.rbegin(), l.rend());

    vector<vi> k_dist;
    vector<vi> l_dist;
    vector<vi> s(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        vi a, b;
        for (int j = 0; j < m; j++) {
            a.pb(i + j + 2),
            b.pb(i + 1 + abs((m + 1) - (j + 1)));
        }
        k_dist.pb(a);
        l_dist.pb(b);
    }
    
    bool placed = true;
    pair<int, int> check = mp(0, 0);
    for (auto x : k) {
        int max_dist = 0;
        pair<int, int> coord = check;
        coord.f = 0;
        coord.s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (k_dist[i][j] <= x and l_dist[i][j] >= max_dist and s[i][j] == 0) {
                    coord.f = i;
                    coord.s = j;
                    max_dist = l_dist[i][j];
                }
            }
        }
        if (coord != check) s[coord.f][coord.s]++;
        else {
            placed = false;
            break;
        }
    }
    for (auto x : s) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
    
    if (placed) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}