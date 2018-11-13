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

vector<vi> dp(1000, vi(1000, -1));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int ct = 0;
    if (a == 1 and b == 1) {
        cout << 0 << endl;
        return 0;
    }
    while (a > 0 and b > 0) {
        if (a < b) {
            a++;
            b -= 2;
        }
        else {
            b++;
            a -= 2;
        }
        ct++;
    }
    cout << ct << endl;
}