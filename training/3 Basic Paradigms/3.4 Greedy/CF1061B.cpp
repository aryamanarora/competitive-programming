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
    vl a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    ll ans = 0, need = a[0];
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < need - 1) {
            ans += (need - a[i + 1]);
            need = a[i + 1];
        }
        else {
            ans++;
            need--;
        }
        // cout << need << " " << ans << endl;
    }
    ans += max(1LL, need);
    cout << sum - ans << endl;
}

/*
USE LONG LONG!!!!
*/