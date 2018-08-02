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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string a;
        getline(cin, a);
        stringstream s(a);
        int n, maxn = 1e9;
        while (s >> n) {
            maxn = max(n, maxn);
        }
        cout << "Case " << i + 1 << ": " << maxn << endl;
    }
}