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

const int MAX = 5001;
    
bool ispal[MAX][MAX] = {false};
int dp[MAX][MAX] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int len = s.length();

    for (int gap = 0; gap < len; gap++) {
        for (int i = 0; i < len - gap; i++) {
            if (gap == 0) {
                ispal[i][i + gap] = true;
            }
            else {
                if (s[i] == s[i + gap]) {
                    if (gap == 1) ispal[i][i + gap] = true;
                    else ispal[i][i + gap] = ispal[i + 1][i + gap - 1];
                }
            }
            dp[i][i + gap] = (ispal[i][i + gap] + dp[i][i + gap - 1] + dp[i + 1][i + gap]) - dp[i + 1][i + gap - 1];
        }
    }

    /*
    for (auto x : dp) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
    */
    

    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << dp[l - 1][r - 1] << endl;
    }
}

/*
USE LONG LONG!!!!
*/