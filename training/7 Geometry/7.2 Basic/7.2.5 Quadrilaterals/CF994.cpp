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

template<typename T>
struct Point {
    T x, y;
    Point() { x = y = T(); };
    Point(T a, T b) : x(a), y(b) {};
};

template<typename T>
bool operator<(const Point<T> &x, const Point<T> &y) {
    return tie(x.x, x.y) < tie(y.x, y.y);
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Point<int>> a, b;
    Point<float> mida, midb;
    for (int i = 0; i < 4; i++) {
        Point<int> add;
        cin >> add.x >> add.y;
        a.push_back(add);
        mida.x += add.x;
        mida.y += add.y;
    }
    for (int i = 0; i < 4; i++) {
        Point<int> add;
        cin >> add.x >> add.y;
        b.push_back(add);
        midb.x += add.x;
        midb.y += add.y;
    }
    
    mida.x /= 4.0;
    midb.x /= 4.0;
    mida.y /= 4.0;
    midb.y /= 4.0;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<Point<int>> pts;
    for (int s = b[0].x; s <= b[2].x; s++) {
        pts.pb(Point(s, b[0].y + (s - b[0].x)));
    }
    for (int s = b[0].x; s <= b[1].x; s++) {
        pts.pb(Point(s, b[0].y - (s - b[0].x)));
    }
    for (int s = b[2].x; s <= b[3].x; s++) {
        pts.pb(Point(s, b[2].y - (s - b[2].x)));
    }
    for (int s = b[1].x; s <= b[3].x; s++) {
        pts.pb(Point(s, b[1].y + (s - b[1].x)));
    }

    bool ans = false;
    for (int i = 0; i < pts.size(); i++) {
        if (pts[i].x >= a[0].x and pts[i].x <= a[3].x and pts[i].y >= a[0].y and pts[i].y <= a[3].y) {
            ans = true;
        }
    }

    if (midb.x >= a[0].x and midb.x <= a[3].x and midb.y >= a[0].y and midb.y <= a[3].y) {
        ans = true;
    }
    
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}