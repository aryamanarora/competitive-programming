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

void construct(int i, int j, vi &ans, vector< vi> &path) {
    ans.pb(i);
    if (path[i][j] != -1 and path[i][j] != j and path[i][j] != i) {
        construct(i, path[i][j], ans, path);
        construct(path[i][j], j, ans, path);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vl> g(n, vl(n, 100000000));
    map<string, int> key; vector<string> rkey(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        key[s] = i;
        rkey[i] = s;
    }
    for (int i = 0; i < n; i++) {
        string a; int b;
        cin >> a >> b;
        string c;
        getline(cin, c);
        for (int j = 0; j < b; j++) {
            string cur;
            getline(cin, c);
            c = c.substr(7);
            for (int k = 0; k < c.length(); k++) {
                if (c[k] == ',') {
                    g[key[cur]][key[a]] = 1;
                    cur = "";
                }
                else if (c[k] != ' ') cur += c[k];
            }
            g[key[cur]][key[a]] = 1;
        }
    }

    vector<vi> path(n, vi(n, -1));
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][k] + g[k][j] < g[i][j]) {
                    path[i][j] = k;
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }

    int minlen = 100000000, ans = -1;
    for (int i = 0; i < n; i++) {
        // cout << rkey[i] << " " << g[i][i] << endl;
        if (g[i][i] < minlen) {
            minlen = g[i][i];
            ans = i;
        }
    }

    if (ans == -1) {
        cout << "SHIP IT" << endl;
        return 0;
    }

    vi anss;
    construct(ans, ans, anss, path);
    vi ansss;
    vector<bool> done(n);
    for (auto x : anss) {
        if (!done[x]) {
            ansss.pb(x);
            done[x] = true;
        }
    }
    reverse(ansss.begin(), ansss.end());
    for (auto x : ansss) cout << rkey[x] << " ";
    cout << endl;
}