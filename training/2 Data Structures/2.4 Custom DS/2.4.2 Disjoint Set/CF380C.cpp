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

    string s;
    cin >> s;

    vi end(s.length()), start(s.length());
    stack<pair<char, int>> a;
    int b = 0;
    for (auto &x : s) {
        if (!a.empty() and a.top().f == '(' and x == ')') {
            start[a.top().s] = 1;
            end[b] = 1;
            a.pop();
        }
        else a.push({x, b});
        b++;
    }
    for (int i = 1; i < b; i++) {
        start[i] += start[i - 1];
        end[i] += end[i - 1];
        cout << i << ": " << start[i] << " " << end[i] << endl;
    }
    
    int n;
    cin >> n;
    int l, r;
    while (n--) {
        cin >> l >> r;
        l--; r--;
        if (l == 0) cout << end[r] * 2 << endl;
        else cout << (end[r] - start[l - 1]) * 2 << endl;
    }
}