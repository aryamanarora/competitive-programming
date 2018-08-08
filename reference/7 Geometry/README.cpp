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
    Point(T a, T b) : x(a), y(b);
}

template <typename T>
struct Polygon {
    vector<Point<T>> p;

    Polygon();
    Polygon(vector<Point<T>> _p) : p(_p);

    void push_back(Point<T> a) {
        if (p.size() == 0) {
            p.pb(a);
            p.pb(a);
        }
        else {
            p.pop_back();
            p.pb(a);
            p.pb(p[0]);
        }
    };

    bool encloses(Point<T> point) {
        int i, j, nvert = p.size();
        bool c = false;

        for (i = 0, j = nvert - 1; i < nvert; j = i++) {
            if(((p[i].y >= point.y ) != (p[j].y >= point.y)) and
                (point.x <= (p[j].x - p[i].x) * (point.y - p[i].y) / (p[j].y - p[i].y) + p[i].x)
            )
            c = !c;
        }

        return c;
    };
}
  