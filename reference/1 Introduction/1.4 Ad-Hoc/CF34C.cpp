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

    set<int> p;

    string s, a;
    getline(cin, s);
    for (auto &x : s) {
        if (x != ',' and x != '\n') a += x;
        else {
            p.insert(stoi(a));
            a = "";
        }
    }
    if (a != "") p.insert(stoi(a));

    vi pp(p.begin(), p.end());
    vii ans;
    bool run = true;
    int first = -1, last = -1;
    for (int i = 0; i < pp.size(); i++) {
        if (pp[i] != pp[i-1] + 1) {
            run = false;
            if (first != -1 and last != -1) {
                ans.pb(mp(first, last));
            }
            first = pp[i];
            last = pp[i];
        }
        else {
            run = true;
            last = pp[i];
        }
    }
    ans.pb(mp(first, last));
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].f == ans[i].s) cout << ans[i].f;
        else cout << ans[i].f << "-" << ans[i].s;
        if (i != ans.size() - 1) cout << ",";
    }
    cout << endl;
}