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

inline namespace graph {
    struct undirected_weighted_graph {
        unsigned long V; // vertices
        unsigned long E; // edges
        vector<vector<pair<int, int>>> list; // adjacency list
        
        void resize(int _V) {
            V = _V;
            list.resize(V + 1);
        }
        void add_edge(int i, int j, int cost) {
            list[i].push_back(mp(j, cost));
            list[j].push_back(mp(i, cost));
            E++;
        }
        vi dijsktra(int root, int end) {
            vl dist;
            vi parent;
            dist.assign(V + 1, INF);
            parent.assign(V + 1, -1);

            priority_queue<ii, vii, greater<ii>> q;
            dist[root] = 0;
            q.push(mp(dist[root], root));

            while (!q.empty()) {
                int v = q.top().s;
                q.pop();

                for (auto &edge : list[v]) {
                    if (dist[v] + edge.s < dist[edge.f]) {
                        dist[edge.f] = dist[v] + edge.s;
                        q.push(mp(dist[edge.f], edge.f));
                        parent[edge.f] = v;
                    }
                }
            }

            vi path;
            if (parent[end] != -1) {
                while (end != -1) {
                    path.pb(end);
                    end = parent[end];
                }
                reverse(path.begin(), path.end());
            }
            else path.pb(-1);
            return path;
        }
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph::undirected_weighted_graph g;

    ll V, E;
    cin >> V >> E;
    g.resize(V);
    int a, b, w;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> w;
        g.add_edge(a, b, w);
    }
    for (auto &x : g.dijsktra(1, V)) {
        cout << x << " ";
    }
    cout << endl;
}