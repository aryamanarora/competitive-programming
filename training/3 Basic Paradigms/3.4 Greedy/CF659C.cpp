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

const int MAX = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    set<int> a; int b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a.insert(b);
    }

    vi ans;
    for (int i = 1; i <= MAX; i++) {
        if (!a.count(i)) {
            if (m - i >= 0) {
                ans.pb(i);
                m -= i;
            }
            else break;
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

/*
USE LONG LONG!!!!
*/