/*
ID: aryaman4
TASK: prefix
LANG: C++14
*/

// #include <bits/stdc++.h> a deficiency of macOS
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

#define P_LENGTH 201
#define S_LENGTH 200001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("prefix.in");
    
    string P[P_LENGTH], cur;
    int i = 0;
    while (fin >> cur) {
        if (cur == ".") break;
        P[i] = cur;
        i++;
    }

    string S = "";
    string ins;
    while (fin >> ins) {
        S += ins;
    }
    cout << S.length() << endl;
    unsigned long pos, ans = 0;
    bool dp[200001];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (pos = 0; pos <= S.length(); pos++) {
        for (int prim = 0; prim < i; prim++) {
            if (dp[pos] == true) {
                if (S.compare(pos, P[prim].length(), P[prim]) == 0) {
                    dp[pos+P[prim].length()] = true;
                    ans = max(ans, (unsigned long) pos+P[prim].length());
                }
            }
        }
    }
    fin.close();

    ofstream fout("prefix.out");
    fout << ans << endl;
    fout.close();
}