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

void ne() {
    cout << "NE" << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi l(n), r(n), u(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        if (r[i] == -1) r[i] = n;
    }
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        if (l[i] == -1) l[i] = n;
    }
    for (int i = 0; i < n; i++) {
        cin >> u[i];
        if (u[i] == -1) u[i] = n;
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        if (d[i] == -1) d[i] = n;
    }

    for (int i = 0; i < n; i++) {
        if (u[i] != n) {
            if (r[u[i]] == n or l[u[i]] == n or d[i] == n) ne();
            if (u[i] + d[i] >= n) ne();
            if (r[u[i]] > i or (n - l[u[i]] - 1 < i)) ne();
        }
        if (d[i] != n) {
            if (r[n - d[i] - 1] == n or l[n - d[i] - 1] == n or u[i] == n) ne();
            if ((r[n - d[i] - 1] > i) or (n - l[n - d[i] - 1] - 1 < i)) ne();
        }
        if (r[i] != n) {
            if (u[r[i]] == n or d[r[i]] == n or l[i] == n) ne();
            if (r[i] + l[i] >= n) ne();
            if (u[r[i]] > i or (n - d[r[i]] - 1 < i)) ne();
        }
        if (l[i] != n) {
            if (u[n - l[i] - 1] == n or d[n - l[i] - 1] == n or r[i] == n) ne();
            if ((u[n - l[i] - 1] > i) or (n - d[n - l[i] - 1] - 1 < i)) ne();
        }
    }
    
    cout << "DA" << endl;
}