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

    string d, e;
    getline(cin, d);
    getline(cin, e);
    int len = d.length();
    map<char, char> verify;
    for (int i = 0; i < len; i++) verify[d[i]] = e[i];

    int n;
    cin >> n;
    vi order; vector<map<char, char>> key(n);
    char c;
    for (int i = 0; i < n; i++) {
        order.pb(i);
        for (char j = 'a'; j <= 'z'; j++) {
            cin >> c;
            key[i][c] = j;
        }
        key[i][' '] = ' ';
    }

    string check;
    getline(cin, check);
    getline(cin, check);
    // for (auto x : verify) cout << x.s;
    // cout << endl;
    vector<vi> dp(26, vi(n));
    for (int i = 0; i < n; i++) {
        for (char j = 'a'; j <= 'z'; j++) {

        }
    }
}

/*
USE LONG LONG!!!!

1--4-67
 2-4-6
*/