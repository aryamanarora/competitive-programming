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

const int MAX = 100001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;
    vector<vi> divs(MAX);
    for (int i = 2; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            divs[j].pb(i);
        }
    }
    vi allowed(MAX, -1);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int ans = 0;
        for (auto j : divs[a]) {
            if (allowed[j] < i - b) ans++;
            allowed[j] = i;
        }
        cout << ans + (b == 0) << endl;
    }
}

/*
USE LONG LONG!!!!
*/