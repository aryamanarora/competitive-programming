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

    int n, a, b, c;
    deque<int> x, y;
    cin >> n >> a;
    for (int i = 0; i < a; i++) {
        cin >> c;
        x.pb(c);
    }
    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> c;
        y.pb(c);
    }

    int fights = 0, sz;
    set<pair<deque<int>, deque<int>>> check;
    deque<int> origx(x), origy(y);
    while (!x.empty() and !y.empty()) {
        sz = check.size();
        check.insert(mp(x, y));
        if (check.size() == sz) {
            cout << -1 << endl;
            return 0;
        }

        if (x.front() > y.front()) {
            x.push_back(y.front());
            x.push_back(x.front());
            x.pop_front();
            y.pop_front();
        }
        else {
            y.push_back(x.front());
            y.push_back(y.front());
            x.pop_front();
            y.pop_front();
        }
        fights++;
    }
    cout << fights << " " << (x.empty() ? 2 : 1) << endl;
}