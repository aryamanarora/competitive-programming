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

    int n, x;
    cin >> n >> x;
    deque<int> a(n);
    bool found = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == x) found = true;
    }
    int ans = 0;
    if (!found) {
        ans++;
        a.pb(x);
        n++;
    }
    sort(a.begin(), a.end());
    while (a[((n + 1) / 2) - 1] != x) {
        if (a[((n + 1) / 2) - 1] > x) {
            a.push_front(0);
            n++;
            ans++;
        }
        else if (a[((n + 1) / 2) - 1] < x) {
            a.pb(1000000);
            n++;
            ans++;
        }
        /*
        for (auto x : a) cout << x << " ";
        cout << endl;
        */
    }
    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/