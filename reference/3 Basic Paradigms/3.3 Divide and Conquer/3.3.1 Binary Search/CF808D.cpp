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

    ll n = 0;
    cin >> n;
    vl a(n);
    ll sum = 0, sum2 = 0;
    map<ll, ll> cts1;
    map<ll, ll> cts2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        cts1[a[i]]++;
    }
    if (sum % 2) {
        cout << "NO" << endl;
        return 0;
    }
    bool ans = false;
    for (int i = 0; i < n and !ans; i++) {
        cts1[a[i]]--;
        cts2[a[i]]++;
        sum2 += a[i];
        if (sum2 == sum / 2) ans = true;
        else if (sum2 > sum / 2) {
            if (cts2[sum2 - (sum / 2)]) ans = true;
        }
        else {
            if (cts1[(sum / 2) - sum2]) ans = true;
        }
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}