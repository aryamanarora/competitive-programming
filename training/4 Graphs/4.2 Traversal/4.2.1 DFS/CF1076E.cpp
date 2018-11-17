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

void dfs(int v, int d, int maxd, ll ct, vector<vi> &g, vi &val) {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;
    vector<vi> g(n);
    vl val(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
}