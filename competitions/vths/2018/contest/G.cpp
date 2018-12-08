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

    int n;
    cin >> n;
    int last = 0, cur = 0, change, passed = 0;
    for (int i = 0; i < n; i++) {
        cin >> change;
        cur += change;
        passed++;
        if (cur >= 80) {
            cout << "Touchdown" << endl;
            return 0;
        }
        if (cur <= -20) {
            cout << "Safety" << endl;
            return 0;
        }
        if (cur < last + 10 and passed == 4) {
            cout << "Nothing" << endl;
            return 0;
        }
        if (cur >= last + 10 and passed <= 4) {
            passed = 0;
            last = cur;
        }
    }
    cout << "Nothing" << endl;
}

/*
USE LONG LONG!!!!
*/