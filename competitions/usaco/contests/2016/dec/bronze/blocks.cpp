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

    ifstream fin("blocks.in");
    ofstream fout("blocks.out");

    int n;
    fin >> n;
    string a, b;
    map<char, int> total;
    while (n--) {
        map<char, int> act, bct;
        fin >> a >> b;
        for (auto x : a) act[x]++;
        for (auto x : b) bct[x]++;
        for (char i = 'a'; i <= 'z'; i++) total[i] += max(act[i], bct[i]);
    }
    for (auto x : total) fout << x.s << endl;
}