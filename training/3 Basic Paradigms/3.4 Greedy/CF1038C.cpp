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

    int n = 0;
    cin >> n;
    vi a(n), b(n);
    ll as = 0, bs = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    
    auto ita = a.begin(), itb = b.begin();
    int ct = 0;
    while (ita != a.end() or itb != b.end()) {
        if (ct % 2 == 0) {
            if (ita != a.end() and itb != b.end()) {
                if (*ita > *itb) {
                    as += *ita;
                    ita++;
                }
                else itb++;
            }
            else if (ita != a.end()) {
                as += *ita;
                ita++;
            }
            else if (itb != b.end()) itb++;
        }
        else {
            if (ita != a.end() and itb != b.end()) {
                if (*itb > *ita) {
                    bs += *itb;
                    itb++;
                }
                else ita++;
            }
            else if (itb != b.end()) {
                bs += *itb;
                itb++;
            }
            else if (ita != a.end()) ita++;
        }
        ct++;
    }

    cout << as - bs << endl;
}