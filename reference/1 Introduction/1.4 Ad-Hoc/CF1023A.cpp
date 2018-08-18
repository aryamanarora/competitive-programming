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

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    if (n > m + 1) {
        cout << "NO" << endl;
        return 0;
    }

    if (a.find('*') == string::npos) {
        if (a == b) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }

    int starpos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == '*') {
            starpos = i;
            if (i == m) {
                cout << "YES" << endl;
                return 0;
            }
            break;
        }
        if (a[i] != b[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int j = 0; j < n - starpos - 1; j++) {
        if (a[j] != b[j]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}