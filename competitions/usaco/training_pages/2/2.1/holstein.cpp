/*
ID: aryaman4
TASK: holstein
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <functional>
#include <bitset>
#include <string>

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
    ifstream fin("holstein.in");

    int v = 0;
    fin >> v;
    vi required(v);
    for (int i = 0; i < v; i++) fin >> required[i];

    int g = 0;
    fin >> g;
    vector<vi> vitamins(g, vi(v));
    for (int i = 0; i < g; i++) {
        for (int j = 0; j < v; j++) fin >> vitamins[i][j];
    }

    string ans = "";

    vector<string> check;
    for (int i = 1; i <= pow(2, g); i++) {
        vi fed(v, 0);
        string s = bitset<32>(i).to_string();
        reverse(s.begin(), s.end());
        check.pb(s);
    }
    stable_sort(check.begin(), check.end(), [](const string& a, const string& b) -> bool {
        return (count(a.begin(), a.end(), '1') < count(b.begin(), b.end(), '1'));
    });

    for (auto s : check) {
        vi fed(v, 0);

        for (int j = 0; j < g; j++) {
            if (s[j] == '1') {
                for (int k = 0; k < v; k++) fed[k] += vitamins[j][k];
            }
        }

        bool okay = true;
        for (int j = 0; j < v; j++) {
            if (fed[j] < required[j]) {
                okay = false;
                break;
            }
        }
        cout << s << ": ";
        for (auto x : fed) cout << x << " ";
        cout << "\n";

        if (okay) {

            ofstream fout("holstein.out");
            string ans = "";
            fout << count(s.begin(), s.end(), '1') << " ";
            for (int j = 0; j < g; j++) {
                if (s[j] == '1') ans += to_string(j + 1) + " ";
            }
            if (ans[ans.length() - 1] == ' ') ans.erase(ans.length() - 1);
            fout << ans;
            fout << "\n";
            return 0;
        }
    }
}

/*
1 2 3 2 3 1

1 1 3 2 3 2
1 1 2 2 3 3
*/