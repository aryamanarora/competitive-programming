/*
ID: aryaman4
TASK: hayfeast
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

    ifstream fin("hayfeast.in");
    ofstream fout("hayfeast.out");

    ll n, m;
    fin >> n >> m;
    vi f(n), s(n);
    for (int i = 0; i < n; i++) fin >> f[i] >> s[i];

    int start = 0, end = 1;
    ll sum = f[0];
    map<int, int> ct;
    ct[s[0]]++;
    ll ans = 1000000010;
    while (true) {
        if (sum < m) {
            if (end == n) break;
            sum += f[end];
            ct[s[end]]++;
            end++;
        }
        else if (sum >= m) {
            ans = min(ans, static_cast<ll>(ct.rbegin()->f));
            sum -= f[start];
            ct[s[start]]--;
            if (ct[s[start]] == 0) ct.erase(s[start]);
            start++;
        }
    }

    fout << ans << endl;
}

/*
4 10
6 15
3 5
4 9
3 6
*/