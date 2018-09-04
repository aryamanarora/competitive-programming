/*
ID: aryaman4
TASK: agrinet
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

const int MAX = 100;
const int INF = numeric_limits<int>::max();

vector<vector<int>> adj(MAX, vi(MAX));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");

    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> adj[i][j];
            if (adj[i][j] == 0) adj[i][j] = INF;
        }
    }

    ll total_weight = 0;
    vector<bool> intree(n, false);
    vii edges(n);
    edges.assign(n, mp(INF, -1));
    edges[0].f = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!intree[j] and (v == -1 or edges[j].f < edges[v].f)) v = j;
        }

        intree[v] = true;
        total_weight += edges[v].f;
        for (int j = 0; j < n; j++) {
            if (adj[v][j] < edges[j].f) edges[j] = mp(adj[v][j], v);
        }
    }

    fout << total_weight << endl;

    fin.close();
    fout.close();
}