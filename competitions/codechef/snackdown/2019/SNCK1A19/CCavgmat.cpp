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
    cout.tie(NULL);

    int t;
    int n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<bool>> arr(n, vector<bool>(m, false));
        vi dists(n + m - 1, 0);
        char a;
        int ct = 0, b;
        for (int i = 0; i < n; i++) {
            queue<int> js;
            for (int j = 0; j < m; j++) {
                cin >> a;
                if (a == '1') {
                    for (int a = 0; a < ct; a++) {
                        b = js.front();
                        dists[j - b]++;
                        js.pop();
                        js.push(b);
                    }
                    arr[i][j] = true;
                    js.push(j);
                    ct++;
                }
            }
            js = queue<int>();
        }
        for ()
    }
}