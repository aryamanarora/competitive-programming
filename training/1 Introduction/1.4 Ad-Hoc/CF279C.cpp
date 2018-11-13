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

#define MAX 100000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, m;
    cin >> n >> m;
    int a[MAX] = {0};
    int inc[MAX] = {0}, dec[MAX] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i-1]) {
            if (i == 0) dec[i] = 1;
            else dec[i] = dec[i-1] + 1;
        }
        else dec[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i-1]) {
            if (i == 0) dec[i] = 1;
            else dec[i] = dec[i-1] + 1;
        }
        else dec[i] = 0;
    }
    for (int i = n-1; i >= 0; i--) {
        if (a[i] <= a[i+1]) {
            inc[i] = inc[i+1] + 1;
        }
        else inc[i] = 0;
    }
    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        l--; r--;
        if (inc[l] + dec[r] + 2 >= r - l + 1) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}