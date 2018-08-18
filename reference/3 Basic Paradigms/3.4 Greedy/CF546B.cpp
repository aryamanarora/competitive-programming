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

    int n = 0, a;
    map<int, int> ct;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ct[a]++;
    }
    for (int i = 1; i < n * 2; i++) ct[i]--;

    int cost = 0;
    while (true) {
        bool dup = false;
        int i;
        for (i = 1; i < n * 2 and !dup; i++) {
            if (ct[i] > 0) dup = true;
        }
        i--;
        if (!dup) {
            break;
        }
        
        int e;
        for (e = i + 1; e < n * 2; e++) {
            if (ct[e] == -1) break;
        }

        ct[i]--;
        ct[e]++;
        cost += (e - i);
    }
    cout << cost << endl;
}