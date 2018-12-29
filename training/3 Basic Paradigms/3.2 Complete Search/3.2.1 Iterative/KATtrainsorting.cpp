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
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    vi a(n);
    for (auto &x : a) cin >> x;

    int ans = 1;
    vi inc(n, 1), dec(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) inc[i] = max(inc[i], inc[j] + 1);
            else dec[i] = max(dec[i], dec[j] + 1);
        }
        ans = max(ans, inc[i] + dec[i] - 1);
    }

    cout << ans << endl;
}

/*
4 4 80
1 1 40
-1 10 60
3 5 50
4 8 70

1 2 3 4 5
*/