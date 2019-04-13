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

    int n, t, x, z; char y;
    cin >> n >> t;

    int r = 0, s = 0;
    priority_queue<ii, vii, greater<ii>> rr, ss;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        if (y == 'R') {
            r++;
            rr.push({x, z});
        }
        else {
            s++;
            ss.push({x, z});
        }
    }

    priority_queue<ll, vl, greater<ll>> q; ll tot_r = 0, tot_s = 0;
    for (int i = 0; i < t; i++) q.push(0LL);

    for (int i = 0; i < n; i++) {
        ll a = q.top();
        q.pop();
        if (!ss.empty()) {
            if (ss.top().f <= a) {
                a += ss.top().s;
                tot_s += (a - ss.top().f);
                ss.pop();
            }
            else if (!rr.empty()) {
                if (ss.top().f <= rr.top().f) {
                    a = ss.top().f + ss.top().s;
                    tot_s += ss.top().s;
                    ss.pop();
                }
                else if (rr.top().f <= a) {
                    a += rr.top().s;
                    tot_r += (a - rr.top().f);
                    rr.pop();
                }
                else {
                    a = rr.top().f + rr.top().s;
                    tot_r += rr.top().s;
                    rr.pop();
                }
            }
            else {
                a = ss.top().f + ss.top().s;
                tot_s += ss.top().s;
                ss.pop();
            }
        }
        else if (rr.top().f <= a) {
            a += rr.top().s;
            tot_r += (a - rr.top().f);
            rr.pop();
        }
        else {
            a = rr.top().f + rr.top().s;
            tot_r += rr.top().s;
            rr.pop();
        }
        q.push(a);
    }

    double sans = static_cast<double>(tot_s) / static_cast<double>(s);
    double rans = static_cast<double>(tot_r) / static_cast<double>(r);
    if (isnan(sans)) cout << "0 ";
    else cout << fixed << setprecision(6) << sans << " ";
    if (isnan(rans)) cout << "0" << endl;
    else cout << fixed << setprecision(6) << rans << endl;
}

/*
USE LONG LONG!!!!

1--4-67
 2-4-6
*/