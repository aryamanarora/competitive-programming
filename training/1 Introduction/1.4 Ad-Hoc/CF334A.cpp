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

    int n;
    cin >> n;
    int n2 = n * n;
    for (int i = 0; i < (n2 / 2); i++) {
        cout << i + 1 << " " << n2 - i << " ";
        if (i % (n / 2) == (n / 2) - 1) cout << endl;
    }
}

/*
4
----
1 16 2 15
3 14 4 13
5 12 6 11
7 10 8 9
*/