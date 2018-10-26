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

    while (true) {
        int c;
        cin >> c;
        cout << bitset<16>(c) << " " << __builtin_popcount(c) << endl;
        for (int a = 1; a < 10; a++) {
            cout << a << ": ";
            for (int b = 1; b < 10; b++) {
                int x = 0;
                for (int i = 0; i < c; i++) {
                    if (__builtin_popcount(i) == a and __builtin_popcount(c - i) == b) {
                        x++;
                    }
                }
                cout << setw(3) << x << " ";
            }
            cout << endl;
        }
    }
}