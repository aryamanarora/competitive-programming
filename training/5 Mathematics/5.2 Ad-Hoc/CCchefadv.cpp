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

bool solve(int n, int m, int x, int y) {
    bool ans = false;
    int a = 1, b = 1;
    if (x == 1 and y == 1) ans = true;
    else if (x == 1) {
        b += ((m - 1) / y) * y;
        if (b == m or (a < n and b == m - 1)) ans = true;
    }
    else if (y == 1) {
        a += ((n - 1) / x) * x;
        if (a == n or (b < n and a == n - 1)) ans = true;
    }
    else {
        a += ((n - 1) / x) * x;
        b += ((m - 1) / y) * y;
        if (a == n and b == m) ans = true;
        else if (a == n - 1 and b == m - 1) ans = true;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int n, m, x, y;
    while (t--) {
        int a = 1, b = 1;
        cin >> n >> m >> x >> y;
        cout << (solve(n, m, x, y) ? "Chefirnemo" : "Pofik" )<< endl;
    }
}