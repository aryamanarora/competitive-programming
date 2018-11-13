#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <complex>

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<string> copy;
    for (int i = 0; i < n; i++) {
        string a;
        for (int j = 0; j < m; j++) {
            a.pb('.');
        }
        copy.pb(a);
    }

    vector<tuple<int, int, int>> ans;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y][x] == '*' and y > 0 and y < n - 1 and x > 0 and x < m - 1) {
                int diff = 1;
                int max_diff = min(x, min(y, min((m - 1) - x, (n - 1) - y)));
                int star_size = 0;
                while (diff <= max_diff) {
                    if (a[y-diff][x] == '*' and a[y][x-diff] == '*' and a[y+diff][x] == '*' and a[y][x+diff] == '*') {
                        if (diff == 1) copy[y][x] = '*';
                        copy[y-diff][x] = '*';
                        copy[y+diff][x] = '*';
                        copy[y][x-diff] = '*';
                        copy[y][x+diff] = '*';
                        star_size++;
                        diff++;
                    }
                    else break;
                }
                if (star_size != 0) ans.pb(make_tuple(y + 1, x + 1, star_size));
            }
        }
    }

    if (copy == a) {
        cout << ans.size() << endl;
        for (auto x : ans) {
            cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
        }
    }
    else cout << -1 << endl;
}