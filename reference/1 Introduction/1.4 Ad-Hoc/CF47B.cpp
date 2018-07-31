#include <iostream>
#include <complex>
#include <vector>
#include <map>

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

map<char, vector<char>> b;
map<char, bool> visited;
bool cycle = false;

int dfs(char x) {
    if (visited[x] == true) {
        cycle = true;
        return 0;
    }
    else visited[x] = true;
    for (auto y : b[x]) {
        dfs(y);
    }
    visited[x] = false;
    return 0;
}

int topological_sort()

int main() {
    vector<string> a(3);
    cin >> a[0] >> a[1] >> a[2];

    for (auto x : a) {
        if (x[1] == '<') {
            b[x[0]].pb(x[2]);
            in_degree[x[2]]++;
        }
        else {
            b[x[2]].pb(x[0]);
            in_degree[x[0]]++;
        }
    }

    dfs('A');
    dfs('B');
    dfs('C');
    if (cycle == true) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
}