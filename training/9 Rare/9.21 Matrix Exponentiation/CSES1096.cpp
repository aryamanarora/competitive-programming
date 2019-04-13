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

const ll MOD = 1e9 + 7;

// square matrix
template<typename T>
struct Matrix {
    int n;
    vector<vector<T>> mat;

    Matrix(int N) : n(N), mat(N, vector<T>(N, T())) {};
    vector<T>& operator[](int idx) {
        return mat[idx];
    }
};

template<typename T>
void operator*=(Matrix<T> &x, Matrix<T> &y) {
    Matrix<T> res(x.n);
    for (int col = 0; col < x.n; col++) {
        for (int i = 0; i < x.n; i++) {
            for (int j = 0; j < x.n; j++) {
                res[i][col] += x[i][j] * y[j][col];
                res[i][col] %= MOD;
            }
        }
    }
    x = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    if (n <= 6) {
        cout << static_cast<int>(pow(2, n - 1)) << endl;
        return 0;
    }

    Matrix<ll> mat(6);
    for (int i = 0; i < 6; i++) mat[0][i] = 1;
    for (int i = 1; i < 6; i++) {
        mat[i][i - 1] = 1;
    }

    Matrix<ll> res(6);
    res.mat = mat.mat;

    ll p = n - 7;
    while (p > 0) {
        if (p % 2) res *= mat;
        p /= 2;
        mat *= mat;
    }

    ll ans = 0;
    ans = (ans + (32 * res[0][0]) % MOD) % MOD;
    ans = (ans + (16 * res[0][1]) % MOD) % MOD;
    ans = (ans + (8  * res[0][2]) % MOD) % MOD;
    ans = (ans + (4  * res[0][3]) % MOD) % MOD;
    ans = (ans + (2  * res[0][4]) % MOD) % MOD;
    ans = (ans + (1  * res[0][5]) % MOD) % MOD;
    cout << ans << endl;
}

/*
USE LONG LONG!!!!

1 1 1 1 1 1  32
1 0 0 0 0 0  16
0 1 0 0 0 0  8
0 0 1 0 0 0  4
0 0 0 1 0 0  2
0 0 0 0 1 0  1

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