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

#define MAX 1e5

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    int sum[MAX];
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) sum[i] = 1;
    }

    int sumsum[MAX], run = 0;
    for (int i = 0; i < n; i++) {
        run += sum[i];
        sumsum[i] = run;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l - 2 < 0) cout << sumsum[r - 2] << endl;
        else cout << sumsum[r - 2] - sumsum[l - 2] << endl;
    }
}

/*
1 2 3 4 5 5

3 4 : 1
2 3 : 1
1 6 : 5
2 6 : 4
*/