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

    string s; int q;
    cin >> s >> q;
    int len = s.length();
    if (len < 3) {
        for (int i = 0; i < q; i++) cout << "YES" << endl;
        return 0;
    }

    vi ctx(len), cty(len), ctz(len);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'x') ctx[i]++;
        else if (s[i] == 'y') cty[i]++;
        else ctz[i]++;
    }

    partial_sum(ctx.begin(), ctx.end(), ctx.begin());
    partial_sum(cty.begin(), cty.end(), cty.begin());
    partial_sum(ctz.begin(), ctz.end(), ctz.begin());

    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        r--; l--;
        int x, y, z;
        if (r - l + 1 < 3) {
            cout << "YES" << endl;
            continue;
        }
        if (l == 0) x = ctx[r], y = cty[r], z = ctz[r];
        else x = ctx[r] - ctx[l - 1], y = cty[r] - cty[l - 1], z = ctz[r] - ctz[l - 1];

        // cout << s.substr(l, r - l + 1) << ": " << x << " " << y << " " << z << endl;
        
        int need = r - (l - 1);
        need /= 3;
        if (abs(x - y) <= 1 and abs(x - z) <= 1 and abs(y - z) <= 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

/*
USE LONG LONG!!!!
*/