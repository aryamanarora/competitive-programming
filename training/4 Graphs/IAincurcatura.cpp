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

    ifstream fin("incurcatura.in");
    ofstream fout("incurcatura.out");

    int p, n, a, b;
    fin >> p >> n;
    set<ii> edges;
    for (int i = 1; i <= n; i++) {
        fin >> a;
        while (a--) {
            fin >> b;
            if (b < i) {
                if (edges.count({b, i})) edges.erase({b, i});
                else edges.insert({b, i});
            }
            else {
                if (edges.count({i, b})) edges.erase({i, b});
                else edges.insert({i, b});
            }
        }
    }

    vector<vi> g(n + 1);
    for (auto x : edges) {
        g[x.f].pb(x.s);
        g[x.s].pb(x.f);
    }

    map<int, int> degree;
    for (auto x : edges) {
        degree[x.f]++;
        degree[x.s]++;
    }

    priority_queue<ii> q;
    for (auto x : degree) q.push({x.s, x.f});

    set<int> ans;
    for (int i = 0; i < p; i++) {
        if (q.top().f == 0) break;
        while (q.top().f != degree[q.top().s]) {
            if (degree[q.top().s] != 0) q.push({degree[q.top().s], q.top().s});
            q.pop();
        }
        ans.insert(q.top().s);
        for (auto v : g[q.top().s]) degree[v]--;
        degree[q.top().s] = 0;
        q.pop();
    }

    for (auto x : ans) fout << x << " ";
    fout << endl;
}

/*
USE LONG LONG!!!!

bcmnvxz
*/