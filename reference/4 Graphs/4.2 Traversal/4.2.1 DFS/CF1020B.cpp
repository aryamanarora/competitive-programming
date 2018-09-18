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

    int n = 0;
    cin >> n;
    vi p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vi ans(n+1, 0);
    int pos;
    for (int i = 1; i <= n; i++) {
        map<int, bool> visited;
        pos = i;
        visited[pos] = true;

        while (true) {
            pos = p[pos];
            if (!visited[pos]) visited[pos] = true;
            else {
                ans[i] = pos;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}