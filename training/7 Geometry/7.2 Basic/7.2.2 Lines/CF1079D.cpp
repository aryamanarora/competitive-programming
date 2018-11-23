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

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(abs(x2 - x1), 2.0) + pow(abs(y2 - y1), 2.0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c, x1, y1, x2, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    double man_dist = abs(x1 - x2) + abs(y1 - y2);

    double closex1 = ((-a * x1) - c) / b, closey1 = ((-b * y1) - c) / a;
    double closex2 = ((-a * x2) - c) / b, closey2 = ((-b * y2) - c) / a;
    /*
    cout << closex1 << " " << closey1 << endl;
    cout << closex2 << " " << closey2 << endl;

    cout << abs(y1 - closex1) + dist(x1, closex1, x2, closex2) + abs(y2 - closex2) << endl;
    cout << abs(y1 - closex1) + dist(x1, closex1, closey2, y2) + abs(x2 - closey2) << endl;
    cout << abs(x1 - closey1) + dist(closey1, y1, x2, closex2) + abs(y2 - closex2) << endl;
    cout << abs(x1 - closey1) + dist(closey1, y1, closey2, y2) + abs(x2 - closey2) << endl;
    cout << man_dist << endl;
    */

    double ans = abs(y1 - closex1) + dist(x1, closex1, x2, closex2) + abs(y2 - closex2); // up/down, up/down
    ans = min(ans,
        abs(y1 - closex1) + dist(x1, closex1, closey2, y2) + abs(x2 - closey2) // up/down, left/right
    );
    ans = min(ans,
        abs(x1 - closey1) + dist(closey1, y1, x2, closex2) + abs(y2 - closex2) // left/right, up/down
    );
    ans = min(ans,
        abs(x1 - closey1) + dist(closey1, y1, closey2, y2) + abs(x2 - closey2) // left/right, left/right
    );
    ans = min(ans, man_dist);
    if (isnan(ans) or isinf(ans)) ans = man_dist;
    cout << fixed << setprecision(10) << ans << endl;
}

/*
USE LONG LONG!!!!
*/