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

    int n;
    cin >> n;
    vi a(n); vector<vi> parents(n);
    vii dist(n, {numeric_limits<int>::max(), 0});
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1) parents[a[i]].pb(i);
        else dist[i] = {0, i};
    }

    for (int i = 0; i < n; i++) if (parents[i].size() != 0) sort(parents[i].begin(), parents[i].end());

    vi mindist(n), dest(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            queue<ii> bfs;
            bfs.push({i, 0});
            int dist = numeric_limits<int>::max();
            while (!bfs.empty()) {
                ii cur = bfs.front();
                bfs.pop();
                dest[cur.f] = i;
                if (parents[cur.f].size() == 0) {
                    if (cur.s < dist) {
                        mindist[i] = cur.f;
                        dist = cur.s;
                    }
                    else if (cur.s == dist) {
                        mindist[i] = min(mindist[i], cur.f);
                    }
                }
                for (auto v : parents[cur.f]) {
                    bfs.push({v, cur.s + 1});
                }
            }
        }
    }

    int x, y;
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> y;
        cout << mindist[dest[y]] << endl;
    }
}

/*
USE LONG LONG!!!!
*/