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

    int l = 0, t = 0, n; string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s[0] == '0') t++;
        if (s[1] == '0') t++;
        if (s[2] == '0') l++;
        if (s[3] == '0') l++;
    }
    int swords = min(l, t) / 2;
    cout << swords << " " << t - (swords * 2) << " " << l - (swords * 2) << endl;
}

/*
USE LONG LONG!!!!
*/