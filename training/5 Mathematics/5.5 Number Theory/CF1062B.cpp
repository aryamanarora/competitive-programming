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
    if (n == 1) {
        cout << "1 0" << endl;
        return 0;
    }
    if (n == 2) {
        cout << "2 0" << endl;
        return 0;
    }
    map<int, int> factors;
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n and n != 1; i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n != 1) factors[n]++;

    int maxi = 0, mini = 1000, res = 1;
    for (auto [a, f] : factors) {
        maxi = max(maxi, f);
        mini = min(mini, f);
        res *= a;
    }
    int diff = ceil(log2(maxi));
    cout << res << " " << diff + (pow(2, diff) - mini == 0 ? 0 : 1) << endl;
}