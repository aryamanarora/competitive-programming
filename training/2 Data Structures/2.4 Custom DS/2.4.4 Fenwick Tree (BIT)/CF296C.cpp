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
    
    int n, m, k;
    cin >> n >> m >> k;
    vl a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<array<int, 3>> ops(m);
    for (int i = 0; i < m; i++) {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
        ops[i][0]--;
    }

    vl op(m, 0);
    int l, r;
    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        l--;
        op[l]++;
        if (r < m) op[r]--;
    }
    partial_sum(op.begin(), op.end(), op.begin());

    vl delta(n, 0);
    for (int i = 0; i < m; i++) {
        delta[ops[i][0]] += op[i] * ops[i][2];
        if (ops[i][1] < n) delta[ops[i][1]] -= op[i] * ops[i][2];
    }
    partial_sum(delta.begin(), delta.end(), delta.begin());

    for (int i = 0; i < n; i++) cout << a[i] + delta[i] << " ";
    cout << endl;
}