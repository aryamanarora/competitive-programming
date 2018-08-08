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

#define MAX 5000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    ii x[MAX];
    for (int i = 0; i < n; i++) {
        cin >> x[i].f >> x[i].s;
    }
    sort(begin(x), begin(x) + n);
    int day = 0;
    for (int i = 0; i < n; i++) {
        if (min(x[i].f, x[i].s) >= day) day = min(x[i].f, x[i].s);
        else day = max(x[i].f, x[i].s);
    }
    cout << day << endl;
}