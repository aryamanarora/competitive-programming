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
    if (n == 1) {
        cout << "0\n0\n";
        return 0;
    }
    if (n == 2) {
        cout << "-1\n";
        return 0;
    }
}

/*
5
4 3 2 1 0
0 2 4 1 3
4 5 1 2 3
*/