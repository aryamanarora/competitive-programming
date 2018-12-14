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

    ifstream cin("rental.in");
    ofstream cout("rental.out");

    int n, m, r, p, q;
    cin >> n >> m >> r;
    vl c(n), rents(r); priority_queue<pair<ll,ll>> cows;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) {
        cin >> p >> q; cows.push({q, p});
    }
    for (int i = 0; i < r; i++) cin >> rents[i];
    sort(c.begin(), c.end());
    sort(rents.rbegin(), rents.rend());
    
    int i;
    ll ans = 0;
    for (i = 0; i < rents.size() and i < n; i++) {
        ans += rents[i];
    }
    int j = i;
    for (; i < n; i++) {
        while (c[i] > 0 and !cows.empty()) {
            pair<ll,ll> x = cows.top();
            cows.pop();
            ll take = min(c[i], x.s);
            ans += take * x.f;
            x.s -= take;
            c[i] -= take;
            if (x.s != 0) cows.push(x);
        }
    }

    ll cur = ans;
    j--;
    for (; j >= 0; j--) {
        cur -= rents[j];
        while (c[j] > 0 and !cows.empty()) {
            pair<ll,ll> x = cows.top();
            cows.pop();
            ll take = min(c[j], x.s);
            cur += take * x.f;
            x.s -= take;
            c[j] -= take;
            if (x.s != 0) cows.push(x);
        }
        ans = max(cur, ans);
    }

    cout << ans << endl;
}

/*
USE LONG LONG!!!!

7 6 4 2 1

*/