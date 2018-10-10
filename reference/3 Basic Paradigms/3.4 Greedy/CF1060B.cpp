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
    if (n < 10) {
        cout << n << endl;
        return 0;
    }
    int ans = 0;

    int nc = n;
    while (nc >= 10) {
        ans += 9;
        nc /= 10;
    }

    string other = to_string(n - (pow(10, ans / 9) - 1));
    for (auto &x : other) ans += (x - '0');

    cout << ans << endl;
}