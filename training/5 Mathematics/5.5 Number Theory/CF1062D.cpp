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
    ll ans = 0;
    for (int i = 2; i <= n / 2; i++) {
        for (int j = i * 2; j <= n; j += i) {
            ans += 4 * (j / i);
        }
    }
    cout << ans << endl;
}

/*
USE LONG LONG!!!!

3 6 -3 -6 2 4 -2 -4 2 6 -2 -6 3
*/