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

const int NUM = 12;

ifstream fin("hamming.in");

void solve() {
    int n;
    fin >> n;
    string a, b;
    fin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    fin >> t;
    while (t--) {
        solve();
    }
}

/*
USE LONG LONG!!!!
*/