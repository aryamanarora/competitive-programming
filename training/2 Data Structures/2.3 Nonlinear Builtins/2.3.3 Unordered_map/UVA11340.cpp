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
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        unordered_map<char, int> keys;
        for (int i = 0; i < k; i++) {
            char a;
            int v;
            cin >> a >> v;
            keys[a] = v;
        }
        double ans = 0.0;
        int m;
        cin >> m;
        string line;
        for (int i = 0; i < m; i++) {
            cin >> line;
            for (auto c : line) {
                ans += (double) keys[c];
            }
        }
        ans /= 100.0;
        cout << fixed << setprecision(2) << ans << endl;
    }
}