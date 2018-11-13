#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>

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
    ll n = 0, k;
    cin >> n >> k;
    vl a(n);
    unordered_set<ll> a_s;
    map<ll, ll> ct;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_s.insert(a[i]);
        ct[a[i]]++;
    }
    if (k > a_s.size()) {
        cout << "-1 -1\n";
        return 0;
    }
    ll ans_l, ans_r;
    for (int i = 0; i < n; i++) {
        ans_l = i;
        if (ct[a[i]] == 1) {
            if (a_s.size() == k) break;
            a_s.erase(a[i]);
        }
        else ct[a[i]]--;
    }
    for (int i = n - 1; i >= 0; i--) {
        ans_r = i;
        if (ct[a[i]] == 1) {
            if (a_s.size() == k) break;
            a_s.erase(a[i]);
        }
        else ct[a[i]]--;
    }

    cout << ans_l + 1 << " " << ans_r + 1 << "\n";
}