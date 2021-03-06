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

    ifstream fin("1.in");

    char a; int n;
    ll sum = 0;
    map<int, int> sums;
    sums[0]++;
    while (fin >> a >> n) {
        if (a == '+') sum += n;
        else sum -= n;
        sums[sum]++;
        if (sums[sum] > 1) cout << sum << endl;
    }
    cout << "---" << endl;
}

/*
USE LONG LONG!!!!
*/