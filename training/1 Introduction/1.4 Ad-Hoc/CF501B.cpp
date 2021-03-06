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
    map<string, string> acc;
    
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (acc.count(a)) {
            acc[b] = acc[a];
            acc.erase(a);
        }
        else acc[b] = a;
    }
    
    cout << acc.size() << endl;
    for (auto &x : acc) cout << x.s << " " << x.f << endl;
}