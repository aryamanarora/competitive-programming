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

const int NUM = 12;

ifstream fin("hello.in");

void solve() {
    vi a(NUM);
    for (int i = 0; i < NUM; i++) fin >> a[i];
    int maxi = a[0];
    for (int i = 1; i < 4; i++) {
        if (a[i] < a[i - 1]) {
            cout << "no" << endl;
            return;
        }
        maxi = max(maxi, a[i]);
    }
    for (int i = 4; i < NUM; i++) {
        if (a[i] < maxi) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    fin >> t;
    while (t--) {
        solve();
    }
}

/*
USE LONG LONG!!!!
*/