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

    ll n, m;
    cin >> n >> m;
    vl a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) a[i] += a[i - 1];
    }
    ll l;
    for (int i = 0; i < m; i++) {
        cin >> l;
        ll room = distance(a.begin(), lower_bound(a.begin(), a.end(), l));
        cout << room + 1 << " " << (room == 0 ? l : l - a[room - 1]) << endl;
    }
}

/*
USE LONG LONG!!!!
*/