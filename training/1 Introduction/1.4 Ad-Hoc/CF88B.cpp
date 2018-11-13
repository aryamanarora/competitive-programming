#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <map>
#include <string>

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

double euclidean_dist(int x1, int y1, int x2, int y2) {
    return sqrt(static_cast<double>(pow(abs(y2 - y1), 2) + pow(abs(x2 - x1), 2)));
}

int main() {
    int n = 0, m = 0;
    double x;
    cin >> n >> m >> x;
    vector<string> a(n);
    vector<pair<int, int>> S;
    map<char, bool> keys;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') S.pb(mp(i, j));
            else keys[toupper(a[i][j])] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto b : S) {
                if (a[i][j] != 'S' and euclidean_dist(i, j, b.f, b.s) <= x) {
                    keys[toupper(a[i][j])] = true;
                    break;
                }
            }
        }
    }
    int q;
    cin >> q;
    int ans = 0;
    char c;
    for (int i = 0; i < q; i++) {
        cin >> c;
        if (keys.find(toupper(c)) == keys.end()) {
            ans = -1;
            break;
        }
        else {
            if (isupper(c)) {
                if (S.empty()) {
                    ans = -1;
                    break;
                }
                else if (keys[toupper(c)] == false) ans++;
            }
        }
    }
    cout << ans << "\n";
}