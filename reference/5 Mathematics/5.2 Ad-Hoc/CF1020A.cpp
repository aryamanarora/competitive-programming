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

    ll n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    ll ta, fa, tb, fb;
    for (int i = 0; i < k; i++) {
        cin >> ta >> fa >> tb >> fb;
        if (ta == tb) {
            cout << abs(fa - fb) << endl;
        }
        else {
            int ans = 0, pos = fa;
            if (fa >= a and fa <= b) {
                ans += abs(ta - tb);
            }
            else {
                ans += min(abs(fa - b), abs(fa - a));
                if (abs(fa - b) < abs(fa - a)) pos = b;
                else pos = a;
                ans += abs(ta - tb);
            }
            ans += abs(pos - fb);
            cout << ans << endl;
        }
    }
}