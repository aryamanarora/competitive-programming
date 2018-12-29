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
    ll n, k;
    cin >> n >> k;
    bitset<64> a(n);
    if (a.count() == k) {
        string s = a.to_string();
        next_permutation(s.begin(), s.end());
        cout << stoull(s, nullptr, 2) << endl;
        return 0;
    }
    while (a.count() != k) {
        if (a.count() > k) {
            int ct = 0, i;
            for (i = 0; i < 64; i++) {
                if (a[i]) {
                    ct++;
                    a[i] = false;
                    if (ct == 2) break;
                }
            }
            i++;
            while (a[i]) {
                a[i] = false;
                i++;
            }
            a[i] = true;
        }
        else {
            for (int i = 0; i < 64; i++) {
                if (!a[i]) {
                    a[i] = true;
                    break;
                }
            }
        }
    }
    cout << a.to_ullong() << endl; 
}