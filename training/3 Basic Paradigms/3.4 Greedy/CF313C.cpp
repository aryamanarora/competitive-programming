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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    set<int> pows;
    for (int i = 0; i <= 11; i++) {
        pows.insert(pow(4, i) - 1);
    }
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (pows.count(i)) {
            // cout << sum - ans << endl;
            ans += sum;
        }
    }
    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/