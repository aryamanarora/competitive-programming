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

ifstream fin("coffee.in");

void solve() {
    int c, p;
    fin >> c >> p;
    int tax = 100 / p;
    map<string, array<int, 3>> costs;
    string a, b, d; int x, y, z;
    for (int i = 0; i < c; i++) {
        fin >> a >> x >> y >> z;
        costs[a] = {x, y, z};
    }
    map<int, int> ans;
    map<string, int> val;
    map<int, string> val2;
    map<string, int> sz;
    sz["small"] = 0;
    sz["medium"] = 1;
    sz["large"] = 2;
    for (int i = 0; i < p; i++) {
        fin >> a >> b >> d;
        if (val.count(a) == 0) {
            val[a] = i;
            val2[i] = a;
        }
        ans[val[a]] += costs[d][sz[b]];
    }
    for (auto [_, q] : ans) {
        q += tax;
        if (q % 5 == 4) q++;
        if (q % 5 == 1) q--;
        cout << val2[_] << " " << q << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    fin >> t;
    while (t--) {
        solve();
    }
}

/*
USE LONG LONG!!!!
*/