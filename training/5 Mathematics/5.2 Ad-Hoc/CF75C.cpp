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

    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    vi divs;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (b % i == 0) divs.pb(i);
            if (i * i != a and b % (a / i) == 0) divs.pb(a / i);
        }
    }
    sort(divs.begin(), divs.end());
    /*
    for (auto x : divs) cout << x << " ";
    cout << endl;
    */

    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int ans = *(upper_bound(divs.begin(), divs.end(), r) - 1);
        cout << (ans < l ? -1 : ans) << endl;
    }
}

/*
USE LONG LONG!!!!
*/