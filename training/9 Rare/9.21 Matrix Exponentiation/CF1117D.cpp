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

const ll MOD = 1000000007;

// square matrix
template<typename T>
struct Matrix {
    int n;
    vector<vector<T>> mat;

    Matrix(int N) : n(N), mat(N, vector<T>(N, T())) {};
    vector<T>& operator[](int idx) {
        return mat[idx];
    }
    vector<vector<T>> exponentiate(int p) {
        Matrix<T> res(n);
        res.mat = mat;
        while (p > 0) {
            if (p % 2) res = res * (*this);
            p /= 2;
            res = res * res;
        }
        return res.mat;
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

    ll n, m;
    cin >> n >> m;

    if (n < m) {
        cout << 1 << endl;
        return 0;
    }

    Matrix<ll> mat(m);
    mat[0][0] = mat[0][m - 1] = 1;
    for (int i = 1; i < m; i++) {
        mat[i][i - 1] = 1;
    }

    Matrix<ll> res(m);
    res.mat = mat.mat;

    ll p = n - m;
    while (p > 0) {
        if (p % 2) res *= mat;
        p /= 2;
        mat *= mat;
    }

    ll ans = 0;
    for (auto &x : res.mat[0]) ans = (ans + x) % MOD;
    cout << ans << endl;
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