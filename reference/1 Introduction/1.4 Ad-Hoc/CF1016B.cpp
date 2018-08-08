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

    int n, m, q;
    cin >> n >> m >> q;
    string a, b;
    cin >> a >> b;

    map<int, int> positions;

    int pos = a.find(b, 0);
    while (pos != string::npos)
    {
        positions[pos]++;
        pos = a.find(b,pos+1);
    }

    map<int, int> ct;
    int current = positions.size();
    for (int i = 0; i < n; i++) {
        if (positions[i-m+1] != 0) {
            current--;
        } 
        ct[i] = current;
    }
    
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << ct[l-1] - ct[r-1] << endl;
    }
}