/*
ID: aryaman4
TASK: humble
LANG: C++14
*/

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

    ifstream fin("humble.in");
    ofstream fout("humble.out");

    int k = 0, n = 0, a;
    fin >> k >> n;

    map<int, ll> primes;
    vi humble;
    for (int i = 0; i < k; i++) {
        fin >> a;
        primes[a] = 0;
    }
    humble.pb(1);

    while (humble.size() != n + 1) {
        ll minhumble = numeric_limits<ll>::max();
        for (auto &x : primes) {
            while (x.f * humble[x.s] <= humble.back()) x.s++;
            minhumble = min(static_cast<ll>(x.f * humble[x.s]), minhumble);
        }
        humble.pb(minhumble);
    }

    fout << humble.back() << endl;

    fin.close();
    fout.close();
}