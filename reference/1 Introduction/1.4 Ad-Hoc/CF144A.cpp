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

    int n, ans;
    cin >> n;
    int min = 101, max = 0, min_pos, max_pos, a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a <= min) {
            min = a;
            min_pos = i;
        }
        if (a > max) {
            max = a;
            max_pos = i;
        }
    }
    if (max_pos < min_pos) ans = max_pos + (n - 1 - min_pos);
    else if (max_pos > min_pos) ans = max_pos + (n - 2 - min_pos);
    else ans = 0;
    cout << ans << endl;
}