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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<int, int> ct;
    map<int, int> ans;
    for (int i = n - 1; i >= 0; i++) {
        ct[arr[i]]++;
        ans[i] = ct.size();
    }

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        cout << ans[q - 1] << endl;
    }

}