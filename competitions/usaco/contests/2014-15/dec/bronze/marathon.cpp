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

int manhattan(ii a, ii b) {
    return abs(a.f - b.f) + abs(a.s - b.s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("marathon.in");
    ofstream fout("marathon.out");

    int n;
    fin >> n;
    vii a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        fin >> a[i].f >> a[i].s;
        if (i > 0) sum += manhattan(a[i], a[i - 1]);
    }
    int maxi = 0;
    for (int i = 1; i < n - 1; i++) {
        maxi = max(maxi, (manhattan(a[i - 1], a[i]) + manhattan(a[i], a[i + 1])) - manhattan(a[i - 1], a[i + 1]));
    }
    cout << sum << endl;
    fout << sum - maxi << endl;
}

/*
USE LONG LONG!!!!
*/