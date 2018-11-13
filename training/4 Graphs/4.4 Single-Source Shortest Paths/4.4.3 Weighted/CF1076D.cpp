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

const ll INF = numeric_limits<ll>::max();

struct edge {
    ll w = INF; int to = -1, id = -1;
    friend istream& operator>> (istream& is, edge& e);
};

bool operator<(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}

istream& operator>>(istream &is, edge& e) {
    is >> e.to >> e.w;
    e.to--;
    return is;
}

vector<vector<edge>> adj;

void dijkstra(vl &d, vi &p, vi &id, int &n, int &k) {
    cout << min(n - 1, k) << endl;

    d[0] = 0;
    set<pair<ll, int>> q;
    q.insert({0, 0});
    for (int i = 0; i < min(n, k + 1); i++) {
        ll dd, v;
        tie(dd, v) = *q.begin();
        q.erase(q.begin());

        if (dd == INF)
            break;

        if (v != 0) cout << id[v] << " ";
        for (auto edge : adj[v]) {
            if (dd + edge.w < d[edge.to]) {
                if (q.count({d[edge.to], edge.to}) != 0) q.erase({d[edge.to], edge.to});
                d[edge.to] = dd + edge.w;
                id[edge.to] = edge.id;
                p[edge.to] = v;
                q.insert({d[edge.to], edge.to});
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    adj.resize(n);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        adj[a].pb({c, b, i});
        adj[b].pb({c, a, i});
    }

    vl d(n, INF); vi p(n, -1), id(n, -1);
    dijkstra(d, p, id, n, k);
}