#include <vector>
#include <complex>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int ct = 1;
int n = 0, q = 0;
vector<vi> tree;
vi order;
map<int, int> subords;
map<int, int> pos;
vector<pair<int, int>> queries;

void dfs(int node) {
    order.pb(node);
    for (auto x : tree[node]) {
        subords[node]++;
        dfs(x);
        subords[node] += subords[x];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        vector<int> a;
        tree.pb(a);
    }
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (i != 0) tree[x-1].pb(i);
    }
    dfs(0);
    for (int i = 0; i < order.size(); i++) {
        pos[order[i]] = i;
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (y > subords[x]) {
            cout << "-1\n";
            continue;
        }
        cout << order[pos[x]+y] + 1 << "\n";
    }
}