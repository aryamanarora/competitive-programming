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

    int n, m, k, q, u, v;
    cin >> n >> m >> k;
    set<int> h;
    for (int i = 0; i < m; i++) {
        cin >> q;
        h.insert(q);
    }
    int pos = 1;
    for (int i = 0; i < k; i++) {
        cin >> u >> v;
        if (h.count(pos)) {
            cout << pos << endl;
            return 0;
        }
        if (pos == u) pos = v;
        else if (pos == v) pos = u;
    }
    cout << pos << endl;
}

/*
USE LONG LONG!!!!
*/