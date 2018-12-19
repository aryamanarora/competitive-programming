/*
ID: aryaman4
TASK: square
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

    ifstream fin("square.in");
    ofstream fout("square.out");

    int x1, y1, x2, y2, x3, y3, x4, y4;
    fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int side = max(max(x2, x4) - min(x1, x3), max(y2, y4) - min(y1, y3));
    fout << side * side << endl;
}