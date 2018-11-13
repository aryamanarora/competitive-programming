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

    int n = 0, k;
    cin >> n >> k;
    vi walk(n);
    for (int i = 0; i < n; i++) cin >> walk[i];

    int add = 0;
    for (int i = 0; i < n - 1; i++) {
        if (walk[i] + walk[i+1] < k) {
            add += walk[i+1] - (k - walk[i]);
            walk[i+1] == k - walk[i];
        }
    }
    
    cout << add << endl;
    for (auto &x : walk) cout << x << " ";
    cout << endl;
}