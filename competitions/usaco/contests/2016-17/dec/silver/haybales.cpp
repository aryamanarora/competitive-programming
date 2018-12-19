/*
ID: aryaman4
TASK: square
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

    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    int n, q;
    fin >> n >> q;
    vl a(n);
    for (int i = 0; i < n; i++) fin >> a[i];
    sort(a.begin(), a.end());
    ll x, y;
    while (q--) {
        fin >> x >> y;
        fout << distance(lower_bound(a.begin(), a.end(), x), upper_bound(a.begin(), a.end(), y)) << endl;
    }
}