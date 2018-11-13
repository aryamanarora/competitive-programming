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

    int r = 0, c;
    cin >> r >> c;
    vector<string> cells(r);
    int rows = 0, cols = 0;
    for (int i = 0; i < r; i++) {
        cin >> cells[i];
        if (cells[i].find('S') == cells.[i].end()) rows++;
    }
    for (int i = 0; i < c; i++) {
        bool found = false;
        for (int j = 0; j < r and !found; j++) {
            if (cells[j][i] == 'S') found = true;
        }
        if (found) cols++;
    }
    cout << cols * r + rows * c - cols * rows << endl;

}