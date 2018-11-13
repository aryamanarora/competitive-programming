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

    int n = 0;
    cin >> n;
    map<int, int> dp;
    vi a(n);
    int maxans = 0, maxi;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = max(dp[a[i-1]] + 1, dp[a[i]]);
        if (dp[a[i]] > maxans) {
            cout << "newmax" << endl;
            maxi = a[i];
        }
    }
    cout << maxans << endl;
    vi ans;
    for (auto i = a.rbegin(); i != a.rend(); i++) {
        if (dp[*i] == maxi) {
            ans.pb(*i);
            maxi--;
        }
    }
    for (auto i = ans.rbegin(); i != ans.rbegin(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}