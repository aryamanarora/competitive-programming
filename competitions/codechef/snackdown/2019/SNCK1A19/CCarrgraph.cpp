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

const int MAX = 51;

struct disjoint_set {
    int n, sets;
    vi parent;

    disjoint_set(int N) : n(N), sets(0), parent(N, -1) {}
    bool has(int v) {
        return (parent[v] != -1);
    }
    void make_set(int v) {
        parent[v] = v;
        sets++;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (b != a) {
            parent[b] = a;
            sets--;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primes;
    for (int i = 2; i < MAX; i++) {
        bool prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) primes.pb(i);
    }
    sort(primes.rbegin(), primes.rend());

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vi w(n);
        disjoint_set dsu(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
            dsu.make_set(i);
        }
        if (n == 1) {
            cout << 0 << endl;
            cout << w[0] << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (gcd(w[i], w[j]) == 1) dsu.make_union(i, j);
        
        int changes = 0;
        for (int i = 0; i < n; i++) {
            bool changed = false;
            for (int j = i + 1; j < n; j++) {
                if (gcd(w[i], w[j]) == 1) dsu.make_union(i, j);
                if (dsu.find_set(i) != dsu.find_set(j)) {
                    for (auto &x : primes) {
                        if (gcd(x, w[j]) == 1) {
                            if (x != w[i]) changed = true;
                            w[i] = x;
                            dsu.make_union(i, j);
                            break;
                        }
                    }
                }
            }
            if (changed) changes++;
        }
        cout << changes << endl;
        for (auto &x : w) cout << x << " ";
        cout << endl;
    }
}