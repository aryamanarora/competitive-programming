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

    int a, b, h;
    cin >> a >> b >> h;
    
    int cur = 0;
    for (int i = 1; cur < h; i++) {
        cur += a;
        if (cur >= h) {
            cout << i << endl;
            return 0;
        }
        cur -= b;
    }
}

/*
USE LONG LONG!!!!
*/