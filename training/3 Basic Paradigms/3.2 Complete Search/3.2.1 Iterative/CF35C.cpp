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

    int n, m, b;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n >> m >> b;
    vii a(b);
    for (int i = 0; i < b; i++) {
        fin >> a[i].f >> a[i].s;
        a[i].f--; a[i].s--;
    }

    vector<vi> dist(n, vi(m, -1));
    for (auto [x, y] : a) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[j][k] == -1) dist[j][k] = (abs(j - x) + abs(k - y));
                else dist[j][k] = min(dist[j][k], (abs(j - x) + abs(k - y)));
            }
        }
    }

    int ans = -1;
    ii anss;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            if (dist[j][k] > ans) {
                ans = dist[j][k];
                anss = {j, k};
            }
        }
    }
    fout << anss.f + 1 << " " << anss.s + 1 << endl;

    fin.close();
    fout.close();
}