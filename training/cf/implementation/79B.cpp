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
#define MIN -1

int main() {
    
    map<int, string> key = {
        { -1, "Waste" },
        { 0, "Carrots" },
        { 1, "Kiwis" },
        { 2, "Grapes" }
    };

    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vi waste;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        waste.pb(x * m + y);
    }
    sort(waste.begin(), waste.end());

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int pos = x * m + y, diff = 0;
        bool bad = false;
        for (auto x : waste) {
            if (x == pos) {
                cout << key[-1] << "\n";
                bad = true;
                break;
            }
            else if (x < pos) diff++;
        }
        if (!bad) cout << key[(pos - diff) % 3] << "\n";
    }
}