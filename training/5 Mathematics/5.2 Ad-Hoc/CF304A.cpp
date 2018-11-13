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
    int ans = 0;

    set<int> squares;
    for (int c = 1; c <= n; c++) {
        squares.insert(c * c);
    }

    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            if (squares.count(a * a + b * b)) ans++;
        }
    }

    cout << ans << endl;
}