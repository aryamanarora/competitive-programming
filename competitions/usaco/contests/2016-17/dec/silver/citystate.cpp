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

    ifstream fin("citystate.in");
    ofstream fout("citystate.out");

    int n;
    fin >> n;
    string a, b;
    map<string, ll> ct;
    for (int i = 0; i < n; i++) {
        fin >> a >> b;
        if (a.substr(0, 2) != b) ct[a.substr(0, 2) + b]++;
    }
    
    ll ans = 0;
    for (auto x : ct) {
        ans += (ct[x.f] * ct[x.f.substr(2, 4) + x.f.substr(0, 2)]);
    }
    fout << fixed << setprecision(0) << (ans / 2) << endl;
}