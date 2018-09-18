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

const ll MAX = sqrt(1000000000000) + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<ll> ans;

    vector<bool> sieve(MAX, true);
    for (int i = 2; i < MAX; i++)
        if (sieve[i])
            for (int j = i * 2; j < MAX; j += i) sieve[j] = false;

    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        if (sqrt(a) * sqrt(a) == a and sieve[sqrt(n)]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}