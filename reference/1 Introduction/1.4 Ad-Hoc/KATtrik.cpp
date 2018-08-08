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
    int pos = 1;
    for (auto c : s) {
        if (pos == 1) {
            if (c == 'A') pos = 2;
            else if (c == 'C') pos = 3;
        }
        else if (pos == 2) {
            if (c == 'A') pos = 1;
            else if (c == 'B') pos = 3;
        }
        else {
            if (c == 'B') pos = 2;
            else if (c == 'C') pos = 1;
        }
    }
    cout << pos << endl;
}