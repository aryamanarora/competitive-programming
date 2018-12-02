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

    ll n, x, y;
    cin >> n >> x >> y;
    if (n > y) {
        cout << -1 << endl;
        return 0;
    }
    ll max = (y - (n - 1));
    if (max * max + (n - 1) < x) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << max << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << 1 << endl;
    }
}

/*
USE LONG LONG!!!!
*/