/*
ID: aryaman4
TASK: comehome
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

const int MAX = 'z' - 'A' + 5;
const int BARN = 'Z' - 'A';
const ll INF = numeric_limits<ll>::max();

vector<vii> dists(MAX); // adjacency list

pair<ll, int> dijkstra(int root, int P) {
    vl dist(MAX);
    dist.assign(MAX, INF);
    pair<int, ll> ans = mp(0, INF);

    priority_queue<ii, vii, greater<ii>> q;
    dist[root] = 0;
    q.push(mp(dist[root], root));

    while (!q.empty()) {
        int v = q.top().s;
        q.pop();

        for (auto &edge : dists[v]) {
            if (dist[v] + edge.s < dist[edge.f]) {
                dist[edge.f] = dist[v] + edge.s;
                q.push(mp(dist[edge.f], edge.f));
            }
        }
    }

    for (int i = 0; i < BARN; i++) {
        if (dist[i] < ans.s) {
            ans.f = i;
            ans.s = dist[i];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("comehome.in");
    int P;
    fin >> P;
    char a, b;
    int j;
    for (int i = 0; i < P; i++) {
        fin >> a >> b >> j;
        dists[a - 'A'].pb(mp(b - 'A', j));
        dists[b - 'A'].pb(mp(a - 'A', j));
    }
    fin.close();

    pair<ll, int> ans = dijkstra(BARN, P);
    ofstream fout("comehome.out");
    fout << static_cast<char>(ans.f + 'A') << " " << ans.s << endl;
    fout.close();
}