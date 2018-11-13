#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ll n = 0, s;
    cin >> n >> s;
    vl arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    ll max_k = 0, min_cost = 10e15;
    ll a = 0, b = n;
    while (a <= b) {
        ll k = (a + b) / 2;

        vl tmp(arr);
        for (ll i = 0; i < n; i++) tmp[i] = tmp[i] + (i + 1) * k; 
        sort(tmp.begin(), tmp.end());

        ll cost = 0;
        for (ll i = 0; i < k; i++) cost += tmp[i];

        if (cost <= s) {
            if (k > max_k) {
                max_k = k;
                min_cost = cost;
            }
            else if (k == max_k) {
                min_cost = min(min_cost, cost);
            }
            a = k + 1;
        }
        else b = k - 1;
    }
    cout << max_k << " " << min_cost << "\n";
}