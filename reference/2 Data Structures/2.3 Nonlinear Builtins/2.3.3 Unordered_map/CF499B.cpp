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

    int n, m;
    cin >> n >> m;
    unordered_map<string, string> key;
    string a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (b.length() < a.length()) key[a] = b;
        else key[a] = a;
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        cout << key[a] << " ";
    }
    cout << endl;
}