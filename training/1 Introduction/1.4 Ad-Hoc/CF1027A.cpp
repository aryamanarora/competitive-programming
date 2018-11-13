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

    int t, a;
    string s;
    cin >> t;
    while (t--) {
        cin >> a >> s;
        bool okay = true;
        for (int i = 0; i < a / 2; i++) {
            if (abs(s[i] - s[a - i - 1]) != 2 and s[i] != s[a - i - 1]) {
                okay = false;
                break;
            }
        }

        if (okay) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}