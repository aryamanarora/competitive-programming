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

inline namespace graph {
    struct unweighted_graph {
        unsigned long V; // vertices
        unsigned long E; // edges
        vector<set<int>> list; // adjacency list

        unweighted_graph(int _V) : list(_V + 1) {
            V = _V;
            E = 0;
        }
        virtual void add_edge(int i, int j) = 0;
        void add_vertices(int _V) {
            V += _V;
            list.resize(list.size() + _V);
        }
        bool is_edge(int i, int j) {
            if (find(list[i].begin(), list[i].end(), j) != list[i].end()) return true;
            else return false;
        }
    };

    struct directed_unweighted_graph : public unweighted_graph {
        directed_unweighted_graph(int _V) : unweighted_graph(_V) {
        }
        void add_edge(int i, int j) {
            list[i].insert(j);
            list[j].insert(i);
        }
    };
}

directed_unweighted_graph g(0);

void dfs(int root, vi &parent, vi &depth, vector<bool> &visited) {
    visited[root] = true;
    for (auto &x : g.list[root]) {
        if (!visited[x]) {
            parent[x] = root;
            depth[x] = depth[root] + 1;
            dfs(x, parent, depth, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    g.add_vertices(n);

    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g.add_edge(a, b);
    }

    vi parent(n+1), depth(n+1);
    vector<bool> visited(n+1, false);
    parent[1] = depth[1] = 0;
    dfs(1, parent, depth, visited);

    vi bfs(n);
    for (int i = 0; i < n; i++) cin >> bfs[i];
    if (bfs[0] != 1) {
        cout << "No" << endl;
        return 0;
    }

    int cur;
    queue<int> q;
    q.push(1);
    for (int i = 1; i < n;) {
        cur = q.front();
        q.pop();
        if (cur == 1) {
            int j;
            for (j = 0; j < g.list[cur].size(); j++) {
                if (parent[bfs[i + j]] != 1) {
                    cout << "No" << endl;
                    return 0;
                }
                q.push(bfs[i + j]);
            }
            i += j;
        }
        else {
            int j;
            for (j = 0; j < g.list[cur].size() - 1; j++) {
                if (parent[bfs[i + j]] != cur) {
                    cout << "No" << endl;
                    return 0;
                }
                q.push(bfs[i + j]);
            }
            i += j;
        }
    }

    cout << "Yes" << endl;
}