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
    ll n;
    cin >> n;
    ll suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        suma += x;
    }
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sumb += x;
    }
    cout << (sumb > suma ? "No" : "Yes") << endl;
}