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

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const ll MAX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    cin >> k;
    ll tmw = k;
    vi ans = {-1};
    ll times = (k / MAX) + 1;
    k += times + 1;
    while (k > 0) {
        ans.pb(min(k, MAX));
        k -= min(k, MAX);
    }

    ll sum = 0;
    for (auto &x : ans) sum += x;
    while ((sum * ans.size()) - (sum + 1) * (ans.size() - 1) < tmw) {
        if (ans.back() == MAX) ans.pb(1);
        ans.back()++;
        sum++;
    }

    cout << ans.size() << endl;
    for (auto &x : ans) cout << x << " ";
    cout << endl;
}

/*
-1 x
    ans: 2x - 2
    res: x
    k = x - 2

-1 x y
    ans: 3x + 3y - 3
    res: 2x + 2y
    k = x + y - 3
*/