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
    vl a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) a[i] += a[i-1];
    }
    int s, f;
    cin >> s >> f;
    int pos = 1, maxsum = a[f - s - 1], sum;
    for (int i = 1; i < n; i++) {
        if (i + f - s - 1 >= n) sum = (a[n - 1] - a[i - 1]) + (a[(i + f - s - 1) - n]);
        else sum = a[i + f - s - 1] - a[i - 1];
        if (sum >= maxsum) {
            pos = i;
            maxsum = sum;
        }
    }
    
    s -= pos;
    if (s <= 0) s += n;
    cout << s << endl;
}