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

    string s;
    cin >> s;
    int upper = 0;
    for (auto &c : s) {
        if (c >= 'A') upper++;
    }
    if (upper <= s.length() - upper) {
        for (auto &c : s) {
            cout << tolower(c);
        }
    }
    else {
        for (auto &c : s) {
            cout << toupper(c);
        }
    }
    cout << endl;
}