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
    if (n == 1 or n == 2) {
        cout << "No" << endl;
        return 0;
    }

    ll sum = (n * (n + 1)) / 2;
    if (sum % 2) {
        cout << "Yes" << endl;
        cout << "1 2" << endl << n - 1 << " 1";
        for (int i = 3; i <= n; i++) cout << " " << i;
        cout << endl;
        return 0;
    }
    
    for (int i = 3; i <= sum / 2 + 1; i += 2) {
        if (sum % i) {
            cout << "Yes" << endl;
            cout << "1 " << i << endl << n - 1 << " 1 2";
            for (int j = 3; j <= n; j++) if (j != i) cout << " " << j;
            cout << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}