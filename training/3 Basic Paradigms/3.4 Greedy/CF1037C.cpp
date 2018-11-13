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
    string a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            if (a[i] != a[i+1] and a[i] != b[i] and a[i+1] != b[i+1]) {
                ans++;
                swap(a[i], a[i+1]);
            }
        }
        if (a[i] != b[i]) ans++;
    }
    cout << ans << endl;
}