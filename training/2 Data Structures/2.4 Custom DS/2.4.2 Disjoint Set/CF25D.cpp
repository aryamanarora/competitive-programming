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

struct disjoint_set {
    int n, sets;
    set<int> setss;
    vi parent;

    disjoint_set(int N) : n(N), sets(0), parent(N) {
    }
    void make_set(int v) {
        parent[v] = v;
        setss.insert(v);
        sets++;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    bool make_union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (b != a) {
            parent[b] = a;
            sets--;
            setss.erase(b);
            return false;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;
    disjoint_set s(n+1);
    for (int i = 1; i <= n; i++) s.make_set(i);
    vii removable;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        if (s.make_union(a, b)) {
            removable.pb({a, b});
        }
    }
    if (s.sets == 1) {
        cout << 0 << endl;
        return 0;
    }
    vi setss(s.setss.begin(), s.setss.end());
    cout << s.sets - 1 << endl;
    for (int i = 0; i < s.sets - 1; i++) {
        cout << removable.back().f << " " << removable.back().s << " ";
        cout << setss[i] << " " << setss[i+1] << endl;
        removable.pop_back();
    }
}