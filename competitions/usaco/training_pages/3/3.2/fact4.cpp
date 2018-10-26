/*
ID: aryaman4
TASK: fact4
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

    ifstream fin("fact4.in");
    ofstream fout("fact4.out");

    int n;
    fin >> n;

    int ans = 1;
    int twos = 0, fives = 0;
    for (int i = 2; i <= n; i++) {
        int j = i;
        while (j % 2 == 0) {
            j /= 2;
            twos++;
        }
        while (j % 5 == 0) {
            j /= 5;
            fives++;
        }
        ans *= j;
        ans %= 10;
    }

    for (int i = 0; i < twos - fives; i++) {
        ans *= 2;
        ans %= 10;
    }

    fout << ans << endl;

    fin.close();
    fout.close();
}