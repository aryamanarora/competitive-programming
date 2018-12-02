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

    
    ll n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n % 2) n = n * 3 + 1;
        else n /= 2;
    }
    cout << 1 << endl;
}

/*
USE LONG LONG!!!!
*/