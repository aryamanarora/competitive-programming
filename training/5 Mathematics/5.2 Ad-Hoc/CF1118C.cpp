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

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    mii ct;
    for (int i = 0, j; i < n * n; i++) {
        cin >> j;
        ct[j]++;
    }

    mii four, two, one;
    for (auto &[x, y] : ct) {
        if (n % 2) {
            if (y % 4 == 0) four[x] = y / 4;
            else if (y % 4 == 1) {
                if (y != 1) four[x] = y / 4;
                one[x] = 1;
            }
            else if (y % 4 == 2) {
                if (y != 2) four[x] = y / 4;
                two[x] = 1;
            }
            else if (y % 4 == 3) {
                if (y != 3) four[x] = y / 4;
                two[x] = 1;
                one[x] = 1;
            }
        }
        else {
            if (y % 4 != 0) {
                cout << "NO" << endl;
                return 0;
            }
            else four[x] = y / 4;
        }
    }

    if (n % 2 and one.size() != 1) {
        cout << "NO" << endl;
        return 0;
    }

    vector<vi> mat(n / 2 + n % 2, vi(n / 2 + n % 2));
    for (int i = 0; i < n / 2 + n % 2; i++) {
        for (int j = 0; j < n / 2 + n % 2; j++) {
            if (n % 2) {
                if (i == n / 2 and j == n / 2) {
                    mat[i][j] = one.begin()->f;
                    continue;
                }
                else if (i == n / 2 or j == n / 2) {
                    if (!two.empty()) {
                        mat[i][j] = two.begin()->f;
                        two.begin()->s -= 1;
                        if (two.begin()->s == 0) two.erase(two.begin());
                    }
                    else if (!four.empty()) {
                        mat[i][j] = four.begin()->f;
                        two[four.begin()->f]++;
                        four.begin()->s -= 1;
                        if (four.begin()->s == 0) four.erase(four.begin());
                    }
                    else {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
                else {
                    if (four.empty()) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    else {
                        mat[i][j] = four.begin()->f;
                        four.begin()->s -= 1;
                        if (four.begin()->s == 0) four.erase(four.begin());
                    }
                }
            }
            else {
                mat[i][j] = four.begin()->f;
                four.begin()->s -= 1;
                if (four.begin()->s == 0) four.erase(four.begin());
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n / 2 + n % 2; i++) {
        for (auto &x : mat[i]) cout << x << " ";
        reverse(mat[i].begin(), mat[i].end());
        for (int j = n % 2; j < n / 2 + n % 2; j++) cout << mat[i][j] << " ";
        reverse(mat[i].begin(), mat[i].end());
        cout << endl;
    }
    for (int i = n / 2 + n % 2 - 1 - n % 2; i >= 0; i--) {
        for (auto &x : mat[i]) cout << x << " ";
        reverse(mat[i].begin(), mat[i].end());
        for (int j = n % 2; j < n / 2 + n % 2; j++) cout << mat[i][j] << " ";
        reverse(mat[i].begin(), mat[i].end());
        cout << endl;
    }
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:
:pray: :prodakcin:

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