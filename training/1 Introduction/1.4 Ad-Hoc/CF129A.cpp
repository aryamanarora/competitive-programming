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

    int n, sum = 0, even = 0; odd = 0;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2) odd++;
        else even++;
        sum += a;
    }
    if (sum % 2) cout << odd << endl;
    else cout << even << endl;
}