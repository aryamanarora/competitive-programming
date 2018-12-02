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

    int n, m;
    cin >> n >> m;
    vii p(2 * n), pp(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> p[i].f;
        p[i].s = i;
        pp[i] = p[i];
    }
    int a, b;
    map<int, int> spec;
    deque<int> order;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        spec[a] = b;
        spec[b] = a;
    }
    sort(pp.rbegin(), pp.rend());
    for (auto x : pp) {
        if (!spec.count(x.s)) order.pb(x.s);
    }

    set<int> visited;
    for (auto [a, b] : spec) {
        if (visited.count(a) or visited.count(b)) continue;
        visited.insert(a);
        visited.insert(b);
        if (p[a].f > p[b].f) {
            order.push_front(a);
            order.pb(b);
        }
        else {
            order.push_front(b);
            order.pb(a);
        }
    }
    visited.clear();

    /*
    for (auto x : order) cout << x << " ";
    cout << endl;
    */

    int t;
    cin >> t;
    t--;
    int last = -1;
    for (int i = 0; i < 2 * n; i++) {
        if (i % 2 == t) {
            if (spec.count(last)) {
                if (!visited.count(spec[last])) {
                    cout << spec[last] + 1 << endl;
                    visited.insert(spec[last]);
                    continue;
                }
            }
            while (visited.count(order.front())) order.pop_front();
            cout << order.front() + 1 << endl;
            visited.insert(order.front());
            order.pop_front();
        }
        else {
            cin >> last;
            last--;
            visited.insert(last);
        }
    }
}

/*
USE LONG LONG!!!!
*/