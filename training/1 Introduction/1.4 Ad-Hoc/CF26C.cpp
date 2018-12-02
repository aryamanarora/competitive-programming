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

    string chars = "abcde";

    int n, m, a, b, d;
    cin >> n >> m >> a >> b >> d;
    if ((n % 2 and m % 2) or ((a * 2 + b * 2 + d * 4) < (n * m))) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<vector<char>> ans(n, vector<char>(m, '.'));
    if (m % 2) {
        for (int j = 0; j < n; j += 2) {
            if (b == 0) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            ans[j][m - 1] = ans[j + 1][m - 1] = (j % 4 ? 'f' : 'g');
            b--;
        }
    }
    if (n % 2) {
        for (int i = 0; i < m; i += 2) {
            if (a == 0) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            ans[n - 1][i] = ans[n - 1][i + 1] = (i % 4 ? 'h' : 'i');
            a--;
        }
    }
    for (int i = 0; i + 1 < m; i += 2) {
        for (int j = 0; j + 1 < n; j += 2) {
            if (i == 0 and j == 0) {
                if (d > 0) {
                    ans[j][i] = ans[j + 1][i] = ans[j][i + 1] = ans[j + 1][i + 1] = 'a';
                    d--;
                }
                else if (b > 1) {
                    ans[j][i] = ans[j + 1][i] = 'a';
                    ans[j][i + 1] = ans[j + 1][i + 1] = 'b';
                    b -= 2;
                }
                else if (a > 1) {
                    ans[j][i] = ans[j][i + 1] = 'a';
                    ans[j + 1][i] = ans[j + 1][i + 1] = 'b';
                    a -= 2;
                }
                else {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }
            else if (i == 0) {
                if (d > 0) {
                    for (auto c : chars) {
                        if (ans[j - 1][i] != c and ans[j - 1][i + 1] != c) {
                            ans[j][i] = ans[j + 1][i] = ans[j][i + 1] = ans[j + 1][i + 1] = c;
                            d--;
                            break;
                        }
                    }
                }
                else if (b > 1) {
                    bool okay1 = false, okay2 = false;
                    for (auto c : chars) {
                        if (ans[j - 1][i] != c) {
                            ans[j][i] = ans[j + 1][i] = c;
                            okay1 = true;
                            break;
                        }
                    }
                    for (auto c : chars) {
                        if (ans[j - 1][i + 1] != c and ans[j][i] != c) {
                            ans[j][i + 1] = ans[j + 1][i + 1] = c;
                            okay2 = true;
                            break;
                        }
                    }
                    if (okay1 and okay2) b -= 2;
                    else {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
                else if (a > 1) {
                    bool okay1 = false, okay2 = false;
                    for (auto c : chars) {
                        if (ans[j - 1][i] != c and ans[j - 1][i + 1] != c) {
                            ans[j][i] = ans[j][i + 1] = c;
                            okay1 = true;
                            break;
                        }
                    }
                    for (auto c : chars) {
                        if (ans[j][i] != c) {
                            ans[j + 1][i] = ans[j + 1][i + 1] = c;
                            okay2 = true;
                            break;
                        }
                    }
                    if (okay1 and okay2) a -= 2;
                    else {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
                else {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }
            else if (j == 0) {
                if (d > 0) {
                    for (auto c : chars) {
                        if (ans[j][i - 1] != c and ans[j + 1][i - 1] != c) {
                            ans[j][i] = ans[j + 1][i] = ans[j][i + 1] = ans[j + 1][i + 1] = c;
                            d--;
                            break;
                        }
                    }
                }
                else if (b > 1) {
                    bool okay1 = false, okay2 = false;
                    for (auto c : chars) {
                        if (ans[j][i - 1] != c and ans[j + 1][i - 1] != c) {
                            ans[j][i] = ans[j + 1][i] = c;
                            okay1 = true;
                            break;
                        }
                    }
                    for (auto c : chars) {
                        if (ans[j][i] != c) {
                            ans[j][i + 1] = ans[j + 1][i + 1] = c;
                            okay2 = true;
                            break;
                        }
                    }
                    if (okay1 and okay2) b -= 2;
                    else {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
                else if (a > 1) {
                    bool okay1 = false, okay2 = false;
                    for (auto c : chars) {
                        if (ans[j][i - 1] != c) {
                            ans[j][i] = ans[j][i + 1] = c;
                            okay1 = true;
                            break;
                        }
                    }
                    for (auto c : chars) {
                        if (ans[j][i] != c and ans[j + 1][i - 1] != c) {
                            ans[j + 1][i] = ans[j + 1][i + 1] = c;
                            okay2 = true;
                            break;
                        }
                    }
                    if (okay1 and okay2) a -= 2;
                    else {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
                else {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }
            else {
                if (d > 0) {
                    for (auto c : chars) {
                        if (ans[j][i - 1] != c and ans[j + 1][i - 1] != c and ans[j - 1][i] != c and ans[j - 1][i + 1] != c) {
                            ans[j][i] = ans[j + 1][i] = ans[j][i + 1] = ans[j + 1][i + 1] = c;
                            d--;
                            break;
                        }
                    }
                }
                else if (b > 1) {
                    bool okay1 = false, okay2 = false;
                    for (auto c : chars) {
                        if (ans[j][i - 1] != c and ans[j - 1][i] != c and ans[j + 1][i - 1] != c) {
                            ans[j][i] = ans[j + 1][i] = c;
                            okay1 = true;
                            break;
                        }
                    }
                    for (auto c : chars) {
                        if (ans[j][i] != c and ans[j - 1][i + 1] != c) {
                            ans[j][i + 1] = ans[j + 1][i + 1] = c;
                            okay2 = true;
                            break;
                        }
                    }
                    if (okay1 and okay2) b -= 2;
                    else {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
                else if (a > 1) {
                    bool okay1 = false, okay2 = false;
                    for (auto c : chars) {
                        if (ans[j][i - 1] != c and ans[j - 1][i] != c and ans[j - 1][i + 1] != c) {
                            ans[j][i] = ans[j][i + 1] = c;
                            okay1 = true;
                            break;
                        }
                    }
                    for (auto c : chars) {
                        if (ans[j][i] != c and ans[j + 1][i - 1] != c) {
                            ans[j + 1][i] = ans[j + 1][i + 1] = c;
                            okay2 = true;
                            break;
                        }
                    }
                    if (okay1 and okay2) a -= 2;
                    else {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
                else {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }
        }
        /*
        for (auto x : ans) {
            for (auto y : x) cout << y;
            cout << endl;
        }
        cout << a << " " << b << " " << d << endl;
        */
    }
    for (auto x : ans) {
        for (auto y : x) cout << y;
        cout << endl;
    }
    // cout << a << " " << b << " " << d << endl;
}

/*
USE LONG LONG!!!!

          .=     ,        =.
  _  _   /'/    )\,/,/(_   \ \
   `//-.|  (  ,\\)\//\)\/_  ) |
   //___\   `\\\/\\/\/\\///'  /
,-"~`-._ `"--'_   `"""`  _ \`'"~-,_
\       `-.  '_`.      .'_` \ ,-"~`/
 `.__.-'`/   (-\        /-) |-.__,'
   ||   |     \O)  /^\ (O/  | .        <-  BESSIE THE COW
   `\\  |         /   `\    /
     \\  \       /      `\ /
      `\\ `-.  /' .---.--.\
        `\\/`~(, '()      ('
         /(O) \\   _,.-.,_)    
        //  \\ `\'`      /
       / |  ||   `""""~"`
     /'  |__||
           `o
*/