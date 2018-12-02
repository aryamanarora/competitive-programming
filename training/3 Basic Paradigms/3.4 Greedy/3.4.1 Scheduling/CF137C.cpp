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

    int n;
    cin >> n;
    vii a(n);
    for (int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
    sort(a.begin(), a.end());
    int i = 0, j = 1, ans = 0;
    while (i != n - 1 and j != n) {
        if (a[j].s < a[i].s) {
            ans++;
            j++;
        }
        else {
            i = j++;
        }
    }
    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/