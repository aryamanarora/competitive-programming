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

    int n, c;
    cin >> n >> c;
    int canignore = 1000 - c, res;
    if (n <= 1000) {
        for (int i = 1; i <= n; i++) {
            cout << 1 << " " << i << endl;
            cin >> res;
            if (res == 1) {
                cout << 3 << " " << i << endl;
                return 0;
            }
        }
    }

    for (int i = canignore + 1; i <= n; i += canignore + 1) {
        cout << 1 << " " << i << endl;
        cin >> res;
        if (res == 1) {
            cout << 2 << endl;
            for (int j = i - canignore; j < i; j++) {
                cout << 1 << " " << j << endl;
                cin >> res;
                if (res == 1) {
                    cout << 3 << " " << j << endl;
                    return 0;
                }
            }
            cout << 3 << " " << i << endl;
            return 0;
        }
        canignore--;
        if (i + canignore + 1 >= n) {
            for (int j = i + 1; j <= n; j++) {
                cout << 1 << " " << j << endl;
                cin >> res;
                if (res == 1) {
                    cout << 3 << " " << j << endl;
                    return 0;
                }
            }
            cout << 3 << " " << n << endl;
            return 0;
        }
    }

}

/*
USE LONG LONG!!!!


*/