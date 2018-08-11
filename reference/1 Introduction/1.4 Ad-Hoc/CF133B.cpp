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

    map<char, int> key {
        { '<', 8 },
        { '>', 9 },
        { '+', 10 },
        { '-', 11 },
        { '.', 12 },
        { ',', 13 },
        { '[', 14 },
        { ']', 15 }
    };

    string a;
    ll ans = 0;
    cin >> a;
    for (int i = a.length() - 1; i >= 0; i--) {
        ans += key[a[i]] << ((a.length() - i - 1) * 4);
        ans %= 1000003;
    }
    cout << ans << endl;
}