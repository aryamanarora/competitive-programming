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

    ifstream fin("stampede.in");
    ofstream fout("stampede.out");

    int n;
    fin >> n;
    vector<pair<ii, bool>> a;
    int x, y, r;
    for (int i = 0; i < n; i++) {
        fin >> x >> y >> r;
        a.pb({{(0 - x - 1) * r, y}, true});
        a.pb({{(0 - x) * r, y}, false});
    }
    sort(a.begin(), a.end());
    
    set<int> ans, cur;
    for (int i = 0; i < a.size(); i++) {
        int j;
        for (j = i; a[j].f.f == a[i].f.f; j++) {
            if (a[j].s) cur.insert(a[j].f.s);
            else cur.erase(a[j].f.s);
        }
        if (!cur.empty()) ans.insert(*cur.begin());
    }

    fout << ans.size() << endl;
}

/*
USE LONG LONG!!!!
*/