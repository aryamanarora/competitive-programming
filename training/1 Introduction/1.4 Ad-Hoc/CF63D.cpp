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

    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    vector<vector<char>> arr(max(b, d), vector<char>(a + c, '.'));
    vector<pair<char, int>> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i].s;
        colors[i].f = i + 'a';
    }
    
    if (b >= d) {
        if (d % 2 == 0) {
            for (int i = 0; i < d; i++) {
                if (i % 2 == 0) {
                    for (int j = 0; j < a + c; j++) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
                else {
                    for (int j = a + c - 1; j >= 0; j--) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
            }
            for (int i = d; i < b; i++) {
                if (i % 2 == 0) {
                    for (int j = 0; j < a; j++) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
                else {
                    for (int j = a - 1; j >= 0; j--) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
            }
        }
        else {
            for (int i = 0; i < d; i++) {
                if (i % 2) {
                    for (int j = 0; j < a + c; j++) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
                else {
                    for (int j = a + c - 1; j >= 0; j--) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
            }
            for (int i = d; i < b; i++) {
                if (i % 2) {
                    for (int j = 0; j < a; j++) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
                else {
                    for (int j = a - 1; j >= 0; j--) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
            }
        }
    }
    else {
        if (b % 2 == 0) {
            for (int i = 0; i < b; i++) {
                if (i % 2) {
                    for (int j = 0; j < a + c; j++) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
                else {
                    for (int j = a + c - 1; j >= 0; j--) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
            }
            for (int i = b; i < d; i++) {
                if (i % 2) {
                    for (int j = a; j < a + c; j++) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
                else {
                    for (int j = a + c - 1; j >= a; j--) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
            }
        }
        else {
            for (int i = 0; i < b; i++) {
                if (i % 2 == 0) {
                    for (int j = 0; j < a + c; j++) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
                else {
                    for (int j = a + c - 1; j >= 0; j--) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
            }
            for (int i = b; i < d; i++) {
                if (i % 2 == 0) {
                    for (int j = a; j < a + c; j++) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
                else {
                    for (int j = a + c - 1; j >= a; j--) {
                        colors.back().s--;
                        arr[i][j] = colors.back().f;
                        if (colors.back().s == 0) colors.pop_back();
                    }
                }
            }
        }
    }

    if (colors.size() == 0) {
        cout << "YES" << endl;
        for (auto x : arr) {
            for (auto y : x) cout << y;
            cout << endl;
        }
    }
    else cout << "NO" << endl;
}

/*
USE LONG LONG!!!!
*/