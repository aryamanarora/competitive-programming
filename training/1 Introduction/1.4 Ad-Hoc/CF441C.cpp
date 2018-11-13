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

    int n, m, k;
    cin >> n >> m >> k;
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (n % 2) {
            for (int j = m - 1; j >= 0; j--) {
                len++;
                if (len == 1) cout << 2 << " ";
                if (k != 1) {
                    cout << i << " " << j << " ";
                    if (len == 2) {
                        cout << endl;
                        len = 0;
                        k--;
                    }
                }
                else {
                    cout << i << " " << j << " ";
                }
            }
        }
        else {
            for (int j = 0; j < m; j++) {
                len++;
                if (len == 1) cout << 2 << " ";
                if (k != 1) {
                    cout << i << " " << j << " ";
                    if (len == 2) {
                        cout << endl;
                        len = 0;
                        k--;
                    }
                }
                else {
                    cout << i << " " << j << " ";
                }
            }
        }
    }
    cout << endl;
}