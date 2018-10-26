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
    
    ll n, t, sum = 0;
    int x;
    cin >> n >> t;
    list<int> a;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.pb(x);
        sum += x;
    }
    ll ans = 0;
    while (true) {
        ans += (t / sum) * n;
        t -= (t / sum) * sum;
        if (t < sum) {
            sum = 0;
            for (auto i = a.begin(); i != a.end(); i++) {
                if (t - sum >= *i) sum += *i;
                else {
                    i = a.erase(i);
                    i--;
                    n--;
                    if (n == 0) break;
                }
            }
        }
        if (sum == 0) break;
    }
    cout << ans << endl;
}