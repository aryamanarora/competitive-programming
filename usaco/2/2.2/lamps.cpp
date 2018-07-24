/*
ID: aryaman4
TASK: lamps
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

#define COMBOS 16

int main() {
    ifstream fin("lamps.in");
    int n = 0, c;
    fin >> n >> c;
    vi on, off;
    int i;
    fin >> i;
    while (i != -1) {
        on.pb(i-1);
        fin >> i;
    }
    fin >> i;
    while (i != -1) {
        off.pb(i-1);
        fin >> i;
    }
    fin.close();

    set<vi> ans;

    for (int i = 0; i < COMBOS; i++) {
        vi lamps(n, 1);
        string check = bitset<4>(i).to_string();
        int ones = count(check.begin(), check.end(), '1');
        if ((c - ones <= 0 or abs(c - ones) % 2 != 0) and c != 0) {
            continue;
        }
        if (c == 0 and i != 0) {
            break;
        }

        if (check[0] == '1') {
            for (int j = 0; j < n; j += 3) lamps[j] = 1 - lamps[j]; // xor with one flips 0 and 1
        }
        if (check[1] == '1') {
            for (int j = 1; j < n; j += 2) lamps[j] = 1 - lamps[j];
        }
        if (check[2] == '1') {
            for (int j = 0; j < n; j += 2) lamps[j] = 1 - lamps[j];
        }
        if (check[3] == '1') {
            for (int j = 0; j < n; j++) lamps[j] = 1 - lamps[j];
        }

        for (auto y : check) cout << y;
        cout << ": ";

        for (auto y : lamps) cout << y;
        cout << endl;

        bool okay = true;
        for (auto a : on) {
            if (lamps[a] != 1) {
                okay = false;
                break;
            }
        }
        for (auto a : off) {
            if (lamps[a] != 0) {
                okay = false;
                break;
            }
        }
        if (okay) ans.insert(lamps);
    }

    ofstream fout("lamps.out");
    if (ans.size() == 0) {
        fout << "IMPOSSIBLE\n";
    }
    else {
        for (auto x : ans) {
            for (auto y : x) fout << y;
            fout << endl;
        }
    }
    fout.close();
}