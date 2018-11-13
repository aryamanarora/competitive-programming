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

/*
bwwwbwwbw
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    if (s.length() == 2) {
        if (s[0] != s[1]) {
            cout << 2 << endl;
            return 0;
        }
        else {
            cout << 1 << endl;
            return 0;
        }
    }
    while (s[0] != s[s.length() - 1]) {
        int i;
        for (i = s.length() - 1; i >= 0; i--) {
            if (i > 0 and s[i] == s[i-1]) {
                break;
            }
        }
        if (i == -1) break;
        reverse(s.begin(), s.begin() + i);
        reverse(s.begin() + i, s.end());
    }
    int ans = 1;
    vi rep(s.length(), 0);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i-1]) rep[i] = rep[i-1] + 1;
        ans = max(ans, rep[i] + 1);
    }
    cout << ans << endl;
}