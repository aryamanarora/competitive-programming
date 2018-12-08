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

    int a, b, c, l;
    cin >> a >> b >> c >> l;
    int ct = 0;
    for (int i = 0; i <= l / a; i++) {
        for (int j = 0; j <= l / b; j++) {
            for (int k = 0; k <= l / c; k++) {
                if (i * a + j * b + k * c == l) {
                    cout << i << " " << j << " " << k << endl;
                    ct++;
                }
            }
        }
    }
    if (ct == 0) cout << "impossible" << endl;
}

/*
USE LONG LONG!!!!
*/