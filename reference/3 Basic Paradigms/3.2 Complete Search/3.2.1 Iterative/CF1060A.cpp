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

    int n, eights = 0;
    cin >> n;
    char a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == '8') eights++;
    }
    n -= eights;
    
    int ans = 0;
    while (eights > 0) {
        if (n >= 10) {
            ans++;
            n -= 10;
            eights--;
        }
        else if (n + eights >= 11) {
            ans++;
            eights -= (11 - n);
            n = 0;
        }
        else break;
    }

    cout << ans << endl;
}