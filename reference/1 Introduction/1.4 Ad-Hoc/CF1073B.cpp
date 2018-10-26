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

    int n, a;
    cin >> n;
    map<int, int> pos;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        pos[a] = i;
    }

    int curpos = 0;
    while (n--) {
        cin >> a;
        if (pos[a] > curpos) {
            cout << pos[a] - curpos << " ";
            curpos = pos[a];
        }
        else cout << 0 << " ";
    }
    cout << endl;
}