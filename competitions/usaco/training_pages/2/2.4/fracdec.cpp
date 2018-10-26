/*
ID: aryaman4
TASK: fracdec
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

const int BUF = 76;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("fracdec.in");
    int n, d;
    fin >> n >> d;
    fin.close();

    vi ans;
    ans.pb(n / d);
    n %= d;
    ans.pb(-1); // decimal point

    stringstream print;

    map<int, vi> remainders;
    int ct = 2;

    ofstream fout("fracdec.out");
    do {
        n *= 10;
        remainders[n].pb(ct);

        // means there is a repetend
        if (remainders[n].size() > 1) {
            int leftpar = remainders[n][0];
            print << ans[0] << '.';
            for (int i = 2; i < ans.size(); i++) {
                if (i == leftpar) print << '(';
                print << ans[i];
            }
            print << ')';
            break;
        }
        
        ans.pb(n / d);
        n %= d;
        ct++;
    } while (n != 0);

    // only if loop ends naturally
    if (n == 0) {
        for (auto &x : ans) {
            if (x == -1) print << '.';
            else print << x;
        }
    }

    // file io :cry:
    string print_string = print.str();
    for (int i = 0; i < print_string.length(); i++) {
        if (i != 0 and i % BUF == 0) fout << endl;
        fout << print_string[i];
    }
    fout << endl;
    fout.close();
}