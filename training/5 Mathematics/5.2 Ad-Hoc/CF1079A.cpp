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

    int n, k, x;
    cin >> n >> k;
    map<int, int> a;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
        maxi = max(maxi, a[x]);
    }
    cout << max(0, (int) (((int) a.size()) * k * ceil((double) maxi / (double) k)) - n) << endl; 
}

/*
USE LONG LONG!!!!
*/