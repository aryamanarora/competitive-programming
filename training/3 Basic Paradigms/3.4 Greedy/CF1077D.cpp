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

    int n, k, z;
    cin >> n >> k;
    map<int, int> a, cnt;
    for (int i = 0; i < n; i++) {
        cin >> z;
        a[z]++;
        cnt[z] = 1;
    }

    priority_queue<ii> q;
    for (auto [x, y] : a) q.push({y, x});
    vi ans;
    while (ans.size() < k) {
        ans.pb(q.top().s);
        cnt[q.top().s]++;
        q.push({a[q.top().s] / cnt[q.top().s], q.top().s});
        q.pop();
    }

    for (auto x : ans) cout << x << " ";
    cout << endl;
}