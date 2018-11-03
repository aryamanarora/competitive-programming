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
    vi p(n), cost(5);
    vl ans(5, 0);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < 5; i++) cin >> cost[i];
    ll money = 0;
    for (auto &prize : p) {
        money += prize;
        for (int i = 4; i >= 0; i--) {
            if (money >= cost[i]) {
                ans[i] += (money / cost[i]);
                money %= cost[i];
            }
        }
    }
    for (auto &ct : ans) cout << ct << " ";
    cout << endl << money << endl;
}