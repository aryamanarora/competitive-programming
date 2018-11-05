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

    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int x = 0; x < 20; x++) {
        for (int i = 0; i < n; i++) {
            if (i < n - 1) a[i] = (a[i] ^ a[i + 1]);
            cout << setw(3) << a[i] << " ";
        }
        cout << endl;
    }
}