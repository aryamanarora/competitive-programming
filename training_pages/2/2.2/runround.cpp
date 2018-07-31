/*
ID: aryaman4
TASK: runround
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <map>

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

bool is_runaround(int n) {
    bool res = true;
    string s = to_string(n);
    int len = s.length();

    sort(s.begin(), s.end());
    if (s[0] == '0') {
        res = false;
        return res;
    }
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i-1]) {
            res = false;
            return res;
        }
    }

    s = to_string(n);
    int pos = 0;
    map<char, int> visited;
    for (int i = 0; i < len; i++) {
        visited[s[pos]]++;
        if (visited[s[pos]] > 1 and i != len - 1) {
            res = false;
            return res;
        }
        pos += s[pos] - '0';
        pos %= len;
    }
    for (auto x : visited) cout << x.f << ": " << x.s << ", ";
    cout << endl;
    if (pos != 0) {
        res = false;
    }
    return res;
}

int main() {
    ifstream fin("runround.in");
    ll n;
    fin >> n;
    n++;
    for (;;n++) {
        if (is_runaround(n)) {
            break;
        }
    }
    ofstream fout("runround.out");
    fout << n << endl;
}