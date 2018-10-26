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
#define mt make_tuple
#define pb push_back
#define f first
#define s second

int n;
vi path, w;
bool done = false;

void dfs(int balance, int last_weight, int depth) {
    path.pb(last_weight);
    if (depth == n) {
        done = true;
        cout << "YES" << endl;
        for (auto x : path) cout << x << " ";
        cout << endl;
        return;
    }
    if (!done) {
        for (auto x : w) {
            if (depth % 2) {
                if (balance - x < 0 and x != last_weight)
                    dfs(balance - x, x, depth + 1);
            }
            else {
                if (balance + x > 0 and x != last_weight)
                    dfs(balance + x, x, depth + 1);
            }
            if (done) break;
        }
    }
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    cin >> a;
    for (int i = 1; i <= 10; i++) {
        if (a[i - 1] == '1') w.pb(i);
    }
    cin >> n;

    for (auto x : w) {
        dfs(x, x, 1);
        if (done) break;
    }
    if (!done) cout << "NO" << endl;
}