#include <bits/stdc++.h>

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<string, int> a;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a[s]++;
        if (a[s] == 1) cout << "OK" << endl;
        else cout << s << a[s] - 1 << endl;
    }
}