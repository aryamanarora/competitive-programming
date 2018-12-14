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

    ifstream cin("measurement.in");
    ofstream cout("measurement.out");

    int n, g;
    cin >> n >> g;

    map<int, int> milk; map<int, set<int>> vals;
    vals[g].insert(-1);

    int day, cow, change; char sign;
    vector<array<int, 3>> changes(n);
    for (int i = 0; i < n; i++) {
        cin >> day >> cow >> sign >> change;
        vals[g].insert(cow);
        if (sign == '+') changes[i] = {day, cow, change};
        else changes[i] = {day, cow, -change};
    }

    sort(changes.begin(), changes.end());
    int ans = 0;
    for (auto x : changes) {
        int oldct = (milk.count(x[1]) ? milk[x[1]] : g);
        int newct = oldct + x[2];
        milk[x[1]] = newct;
        set<int> old = vals.rbegin()->s;
        
        vals[oldct].erase(x[1]);
        if (vals[oldct].size() == 0) vals.erase(oldct);
        vals[newct].insert(x[1]);

        if (vals.rbegin()->s != old) ans++;
        // cerr << vals.rbegin()->f << " " << vals.rbegin()->s << endl;
    }

    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/