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

    int n, a, b, m, l;
    cin >> n >> a >> b;
    vii p;
    int dup = 0;
    for (int i = 1; i < n; i++) {
        cin >> m >> l;
        if (a != m or b != l) p.pb({m, l});
        else dup++;
    }

    vector<pair<double, int>> changes;
    for (auto x : p) {
        if (x.s == b) continue;
        double y = static_cast<double>(x.f - a) / static_cast<double>(b - x.s);
        if (y < 0) continue;
        changes.pb({y, (b > x.s ? 1 : -1)});
    }

    sort(changes.begin(), changes.end());
    // for (auto x : changes) cout << x.f << " " << x.s << endl;
    p.pb({a, b});
    sort(p.begin(), p.end());

    int pos = n - distance(p.begin(), lower_bound(p.begin(), p.end(), mp(a, b))) - dup;
    // cout << pos << endl;
    int mini = pos, maxi = pos, sz = changes.size();
    for (int i = 0; i < sz; i++) {
        int bel = 0, abo = 0;
        for (int j = i; j < sz and changes[j].f - changes[i].f <= 1e-9; j++) {
            if (changes[j].s == -1) bel++;
            else abo++;
            i = j;
        }
        mini = min(mini, pos - abo);
        maxi = max(maxi, pos + bel);
        pos += bel;
        pos -= abo;
    }

    cout << mini << " " << maxi + dup << endl;
}

/*
USE LONG LONG!!!!

8 1  
7 10
0 11
*/