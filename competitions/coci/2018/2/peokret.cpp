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

    int a, b, y;
    vii x;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> y;
        x.pb({y, 0});
    }
    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> y;
        x.pb({y, 1});
    }
    sort(x.begin(), x.end());
    
    int ans1 = -1, ans2 = 0;
    int as = 0, bs = 0;
    bool winner = false;
    for (int i = 0; i < a + b; i++) {
        if (x[i].f > 1440 and ans1 == -1) ans1 = as + bs;
        if (i == 0) {
            if (x[i].s == 1) {
                as++;
                winner = true;
            }
            else {
                bs++;
                winner = false;
            }
        }
        else {
            if (x[i].s == 1) as++;
            else bs++;
            if (bs > as and winner) {
                winner = false;
                ans2++;
            }
            if (as > bs and !winner) {
                winner = true;
                ans2++;
            }
        }
    }
    if (ans1 == -1) ans1 = as + bs;

    cout << ans1 << endl;
    cout << ans2 << endl;
}