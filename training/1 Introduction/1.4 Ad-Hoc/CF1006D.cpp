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
    int n = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<bool> okay(n, false);

    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        map<char, int> x;
        x[a[i]]++;
        x[a[n - i - 1]]++;
        x[b[i]]++;
        x[b[n - i - 1]]++;
        if (x.size() == 3) {
            if (a[i] == a[n - i - 1]) ans += 2;
            else ans++;
        }
        else if (x.size() == 4) {
            ans += 2;
        }
        else if (x.size() == 2) {
            if ((*x.begin()).s != 2) ans++;
        }
    }
    if (n % 2) {
        if (a[n / 2] != b[n / 2]) ans++;
    }
    cout << ans << "\n";
}