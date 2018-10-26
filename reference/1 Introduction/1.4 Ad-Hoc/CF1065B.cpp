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

const int MAX = 201;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    ll maxi, mini;
    if (m == 0) maxi = mini = n;
    else {
        maxi = max(0LL, n - (2 * m));
        ll pos = sqrt(2LL * m);
        ll tri = ((pos * (pos + 1)) / 2LL);
        if (m > tri) mini = max(0LL, n - pos - 2);
        else mini = max(0LL, n - pos - 1);
    }
    cout << maxi << " " << mini << endl;
}