#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    int n, b, h, w;
    while(cin >> n >> b >> h >> w;) {

        int min_cost = 1e9;
        for (int i = 0; i < h; i++) {
            int cost;
            cin >> cost;

            for (int i = 0; i < w; i++) {
                int rooms;
                cin >> rooms;
                if (rooms >= n) {
                    cost *= n;
                    break;
                }
            }

            min_cost = min(min_cost, cost);
        }

        if (min_cost <= b) cout << min_cost << endl;
        else cout << "stay home" << endl;
    }
}