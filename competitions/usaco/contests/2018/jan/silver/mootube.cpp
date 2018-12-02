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

int get_dist(int x, int y, dist)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    int n, q;
    fin >> n >> q;
    vector<vi> dist(n, vi(n, -1));
    int x, y, w;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y >> w;
        dist[x][y] = w;
        dist[y][x] = w;
    }
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << get_dist(x, y) << endl;
    }
}

/*
USE LONG LONG!!!!
*/