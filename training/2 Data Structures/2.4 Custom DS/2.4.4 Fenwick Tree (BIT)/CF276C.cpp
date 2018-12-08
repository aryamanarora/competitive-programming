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

    int n, q;
    cin >> n >> q;

    priority_queue<ll> pq;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }

    vl prefix_sum(n, 0);
    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        l--; r--;
        prefix_sum[l]++;
        if (r != n - 1) prefix_sum[r + 1]--;
    }

    for (int i = 1; i < n; i++) prefix_sum[i] += prefix_sum[i - 1];
    sort(prefix_sum.begin(), prefix_sum.end());

    ll ans = 0;
    while (!pq.empty() and !prefix_sum.empty()) {
        ans += pq.top() * prefix_sum.back();
        pq.pop(); prefix_sum.pop_back();
    }

    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/