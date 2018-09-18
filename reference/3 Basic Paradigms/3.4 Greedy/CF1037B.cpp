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

    int n = 0, s;
    cin >> n >> s;
    vl arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    ll ans = 0;
    if (s > arr[n / 2]) {
        for (int i = n / 2; i < n; i++) {
            if (arr[i] < s) ans += (s - arr[i]);
            else break;
        }
    }
    else if (s < arr[n / 2]) {
        for (int i = n / 2; i >= 0; i--) {
            if (arr[i] > s) ans += (arr[i] - s);
            else break;
        }
    }

    cout << ans << endl;
}