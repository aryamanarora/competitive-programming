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

struct coord {
    ll x, y;
    coord() : x(0), y(0) {};
    coord(ll a, ll b) : x(a), y(b) {};
};

struct rect {
    coord l, r;
    rect() : l(), r() {};
    rect(coord a, coord b) : l(a), r(b) {};
    ll area() {
        return ((r.x - l.x + 1LL) * (r.y - l.y + 1LL));
    };
};

ll black(coord a) {
    return (
        (a.x / 2LL) * (a.y / 2LL + a.y % 2LL) +
        (a.x / 2LL + a.x % 2LL) * (a.y / 2LL)
    );
}

ll black(rect a) {
    return black(a.r) - black({a.l.x - 1LL, a.r.y}) - black({a.r.x, a.l.y - 1LL}) + black({a.l.x - 1LL, a.l.y - 1LL});
}

ll white(coord a) {
    return (a.x * a.y) - black(a);
}

ll white(rect a) {
    return a.area() - black(a);
}

rect overlap(rect a, rect b) {
    if (min(a.r.x, b.r.x) - max(a.l.x, b.l.x) < 0 or
        (min(a.r.y, b.r.y) - max(a.l.y, b.l.y) < 0)) {
        return rect(coord(0LL, 0LL), coord(0LL, 0LL));
    }
    return rect(
        coord(max(a.l.x, b.l.x), max(a.l.y, b.l.y)),
        coord(min(a.r.x, b.r.x), min(a.r.y, b.r.y))
    );
}

void solve() {
    coord board;
    cin >> board.y >> board.x;
    rect w, b;
    cin >> w.l.x >> w.l.y >> w.r.x >> w.r.y;
    cin >> b.l.x >> b.l.y >> b.r.x >> b.r.y;

    ll bl = black(board), wh = white(board);

    ll bl_rem = black(w) - black(overlap(w, b));
    bl -= bl_rem;
    wh += bl_rem;

    ll bl_add = white(b);
    bl += bl_add;
    wh -= bl_add;

    /*
    rect over = overlap(w, b);
    cout << "overlap: (" << over.l.x << ", " << over.l.y << "), (" << over.r.x << ", " << over.r.y << ")" << endl;
    cout << "black removed / white added: " << black(w) << endl;
    cout << "black readded / white unadded: " << black(overlap(w, b)) << endl;
    cout << "white removed / black added: " << white(b) << endl;
    */

    cout << wh << " " << bl << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}

/*
USE LONG LONG!!!!
*/