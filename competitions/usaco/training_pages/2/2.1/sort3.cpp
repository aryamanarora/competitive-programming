/*
ID: aryaman4
TASK: sort3
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>

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

int main() {
    ifstream fin("sort3.in");
    int n = 0;
    fin >> n;
    vi a(n);
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
        if (a[i] == 1) ones++;
        else if (a[i] == 2) twos++;
        else threes++;
    }

    int ans = 0, diff;
    vector<vi> wrong(4, vi(4));
    for (int i = 0; i < ones; i++) {
        if (a[i] != 1) wrong[1][a[i]]++;
    }
    for (int i = ones; i < ones + twos; i++) {
        if (a[i] != 2) wrong[2][a[i]]++;
    }
    for (int i = ones + twos; i < n; i++) {
        if (a[i] != 3) wrong[3][a[i]]++;
    }

    diff = min(wrong[1][2], wrong[2][1]);
    ans += diff;
    wrong[1][2] -= diff;
    wrong[2][1] -= diff;

    diff = min(wrong[2][3], wrong[3][2]);
    ans += diff;
    wrong[2][3] -= diff;
    wrong[3][2] -= diff;

    diff = min(wrong[1][3], wrong[3][1]);
    ans += diff;
    wrong[1][3] -= diff;
    wrong[3][1] -= diff;

    diff = 0;


    for (auto x : wrong) {
        for (auto y : x) diff += y;
    }
    ans += (diff / 3) * 2;

    ofstream fout("sort3.out");
    fout << ans << "\n";
}

/*
1 2 3 2 3 1

1 1 3 2 3 2
1 1 2 2 3 3
*/