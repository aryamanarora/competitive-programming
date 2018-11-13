#include <iostream>
#include <complex>
#include <tuple>
#include <vector>

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

#define MAX_S 100002

struct soldier {
    int l, r;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    soldier line[MAX_S];

    int S, B;
    while (cin >> S >> B) {
        if (S == 0 and B == 0) break;
        for (int i = 1; i <= S; i++) {
            line[i].l = i - 1;
            line[i].r = i + 1;
        }
        for (int i = 0; i < B; i++) {
            int l, r;
            cin >> l >> r;
            
            if (line[l].l != 0 and line[l].l != S + 1) {
                cout << line[l].l << " ";
            }
            else cout << "* ";

            if (line[r].r != 0 and line[r].r != S + 1) {
                cout << line[r].r << endl;
            }
            else cout << "*" << endl;
            line[line[l].l].r = line[r].r;
            line[line[r].r].l = line[l].l;
        }
        cout << "-" << endl;
    }
}