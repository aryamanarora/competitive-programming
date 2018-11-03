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
    if (n % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i <= n / 2; i++) cout << (n - 1) - 2 * i << " ";
    for (int i = 0; i < n / 2; i++) cout << (n - 2) - 2 * i << " ";
    cout << endl;
    for (int i = n - 1; i >= 0; i--) cout << i << " ";
    cout << endl;
}

/*
0 1 2 3 4
4 2 0 3 1
4 3 2 1 0

0 1 2 3 4 5 6
6 4 2 0 5 3 1
6 5 4 3 2 1 0
*/