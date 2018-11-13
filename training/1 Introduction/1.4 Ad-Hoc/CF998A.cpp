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

    int n = 0;
    cin >> n;

    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }

    vi a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    auto it = min_element(a.begin(), a.end())
    if (sum - *it == *it) {
        cout << -1 << endl;
        return 0;
    }
    else {
        bool ignored = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == *it and !ignored) {
                ignored = true;
            }
            else cout << i + 1 << " ";
        }
        cout << endl;
    }

}