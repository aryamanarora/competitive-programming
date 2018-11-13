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

    int n, k;
    string s;
    cin >> n >> k >> s;

    map<char, int> m;
    for (auto &x : s) m[x]++;
    
    int ct = m['A'];
    for (char i = 'B'; i < 'A' + k; i++) {
        ct = min(ct, m[i]);
    }

    cout << ct * k << endl;
}