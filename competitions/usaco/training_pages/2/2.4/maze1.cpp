/*
ID: aryaman4
TASK: maze1
LANG: C++14
*/

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

const int MAX = 3800;

inline namespace graph {
    struct unweighted_graph {
        unsigned long V; // vertices
        unsigned long E; // edges
        vector<vector<int>> list; // adjacency list

        unweighted_graph(int _V) {
            V = _V;
            list.resize(V + 1);
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
    struct undirected_unweighted_graph : public unweighted_graph {
        undirected_unweighted_graph(int _V) : unweighted_graph(_V) {
        }
        void add_edge(int i, int j) {
            list[i].push_back(j);
            list[j].push_back(i);
        }
    };
}

int w, h;
graph::undirected_unweighted_graph g(MAX);

int pos(int i, int j) {
    return (i * w) + (j / 2) + 1;
}

vi bfs(int source) {
    vi dist;
    dist.assign(w * h + 1, -1);
    queue<int> q;
    map<int, bool> visited;

    q.push(source);
    visited[source] = true;
    dist[source] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g.list[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("maze1.in");
    fin >> w >> h;
    vi exits;
    string t, m;

    getline(fin, t);
    for (int i = 0; i < h; i++) {
        getline(fin, t);
        getline(fin, m);
        // top
        for (int j = 0; j < w * 2; j += 2) {
            if (t[j+1] == ' ') {
                if (i == 0) exits.pb(pos(i, j));
                else g.add_edge(pos(i, j), pos(i - 1, j));
            }
        }
        // mid
        for (int j = 0; j < w * 2; j += 2) {
            if (m[j] == ' ') {
                if (j == 0) exits.pb(pos(i, j));
                else g.add_edge(pos(i, j), pos(i, j - 2));
            }
        }
        if (m[w * 2] == ' ') exits.pb(pos(i, w * 2 - 2));
    }
    getline(fin, t);
    for (int j = 0; j < w * 2; j += 2) {
        if (t[j+1] == ' ') exits.pb(pos(h - 1, j));
    }
    // cout << "ye" << endl;

    fin.close();

    vi min_dist, dist;
    min_dist.assign(w * h + 1, 100000);
    for (auto &x : exits) {
        dist = bfs(x);
        for (int i = 0; i < dist.size(); i++) {
            min_dist[i] = min(min_dist[i], dist[i]);
        }
    }

    ofstream fout("maze1.out");
    fout << *max_element(min_dist.begin(), min_dist.end()) << endl;
    fout.close();

    for (int i = 1; i <= w * h; i++) {
        cout << i << " (" << min_dist[i] << "): ";
        for (auto &j : g.list[i]) cout << j << " ";
        cout << endl;
    }
    cout << endl;
    for (auto &x : exits) cout << x << " ";
    cout << endl;
}