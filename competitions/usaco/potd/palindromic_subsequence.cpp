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

    string s;
    cin >> s;
    int n = s.length();
    vector<vi> pos(10);
    for (int i = 0; i < n; i++) pos[s[i] - '0'].pb(i);
    vii dp(n, {0, -1});
    dp[0] = {(pos[s[0] - '0'].back() == 0 ? 1 : 2), pos[s[0] - '0'].back()};
    pos[s[0]].pop_back();
    for (int i = 1; i < n; i++) {
        if (pos[s[i]].size()) {
            int res = 1, poss;
            for (int j = 0; j < i; j++) {
                
            }
        }
    }
}