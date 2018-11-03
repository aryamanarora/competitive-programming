/*
ID: aryaman4
TASK: blocks
LANG: C++14
*/

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

    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");

    int m, n, k;
    fin >> m >> n >> k;
    for (int i = 0; i < m; i++) {
        string s;
        fin >> s;
        for (int j = 0; j < k; j++) {
            for (auto c : s) {
                for (int l = 0; l < k; l++) fout << c;
            }
            fout << endl;
        }
    }
}