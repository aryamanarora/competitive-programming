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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vi a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort (a.begin(), a.end());
        cout << "Case " << i + 1 << ": " << a[1] << endl;
    }
}