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

    ifstream cin("lifeguards.in");
    ofstream cout("lifeguards.out");

    int n;
    cin >> n;
    vii events(n * 2); int ct = 2;
    for (auto &x : events) {
        cin >> x.f;
        x.s = (ct % 2 ? -1 : 1) * (ct / 2);
        ct++;
    }
    sort(events.begin(), events.end());

    set<int> active;
    int alone = 0, start = -1, end = -1, len = 0; vi alonet(n);
    for (auto &x : events) {
        if (x.s < 0) {
            if (active.size() == 2) alone = x.f;
            else if (active.size() == 1) {
                alonet[*active.begin() - 1] += (x.f - alone);
                end = x.f;
                len += end - start;
            }
            active.erase(-x.s);
        }
        else {
            if (active.size() == 1) alonet[*active.begin() - 1] += (x.f - alone);
            else if (active.size() == 0) start = x.f;
            active.insert(x.s);
        }
    }

    cout << len - *min_element(alonet.begin(), alonet.end()) << endl;
}

/*
USE LONG LONG!!!!
*/