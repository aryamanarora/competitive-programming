/*
ID: aryaman4
TASK: cowtour
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

const double INF = std::numeric_limits<double>::infinity();
const int MAX = 151;

double dists[MAX][MAX];
double farthest[MAX];

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

int main() {
    // clock_t start = clock();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("cowtour.in");
    int n;
    fin >> n;

    vector<Point> pts(n);
    for (int i = 0; i < n; i++) fin >> pts[i].x >> pts[i].y;

    string a;
    for (int i = 0; i < n; i++) {
        fin >> a;
        for (int j = i; j < n; j++) {
            if (a[j] == '1') dists[i][j] = dists[j][i] = dist(pts[i], pts[j]);
            else dists[i][j] = dists[j][i] = INF;
        }
    }

    // cout << "file io: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;

    fin.close();

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                dists[i][j] = dists[j][i] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }

    // cout << "floyd-warshall: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;

    // find farthest distance from each point
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j and dists[i][j] != INF) farthest[i] = max(farthest[i], dists[i][j]);
        }
    }

    // cout << "farthest point: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;

    // finding the minimum combined diameter of the two fields
    double ans = INF, diameter = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (dists[i][j] == INF) ans = min(ans, farthest[i] + farthest[j] + dist(pts[i], pts[j]));
                else diameter = max(diameter, dists[i][j]);
            }
        }
    }
    ans = max(ans, diameter);

    // cout << "completion: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;

    ofstream fout("cowtour.out");
    fout << fixed << setprecision(6) << ans << endl;
    fout.close();

    // cout << "file io: " << (clock() - start) / (double) CLOCKS_PER_SEC << endl;
}