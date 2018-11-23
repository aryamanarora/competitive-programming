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

    int p = 0, s = 0;
    cin >> p >> s;
    vii ans;
    for (int i = 0; i < p; i++) {
        vii problem(s);
        for (int j = 0; j < s; j++) cin >> problem[j].f;
        for (int j = 0; j < s; j++) cin >> problem[j].s;
        sort(problem.begin(), problem.end());
        int n = 0;
        for (int j = 0; j < s - 1; j++) {
            if (problem[j].s < problem[j+1].s) n++;
        }
        ans.pb(mp(n, i + 1));
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) cout << x.s << endl;
}