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
    
    while (true) {
        ll t;
        cin >> t;
        if (t == 0) break;

        ll x, y;
        cin >> x >> y;
        
        for (int i = 0; i < t; i++) {
            ll a, b;
            cin  >> a >> b;

            if (b > y) cout << "N";
            else if (b < y) cout << "S";
            else cout << "divisa";
            
            if (a > x) cout << "E";
            else if (a < x) cout << "W";

            cout << endl;
        }
    }
}