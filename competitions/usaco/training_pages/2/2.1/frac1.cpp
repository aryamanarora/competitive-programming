/*
ID: aryaman4
TASK: frac1
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ifstream fin("frac1.in");
    int n;
    fin >> n;
    vector<pair<int, int>> ans;
    ans.pb(mp(0, 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (__gcd(i, j) == 1) ans.pb(mp(j, i));
        }
    }
    ans.pb(mp(1, 1));
    sort(ans.begin(), ans.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        return (static_cast<double>(a.f) / static_cast<double>(a.s) < static_cast<double>(b.f) / static_cast<double>(b.s));
    });
    ofstream fout("frac1.out");
    for (auto x : ans) {
        fout << x.f << "/" << x.s << "\n";
    }
}