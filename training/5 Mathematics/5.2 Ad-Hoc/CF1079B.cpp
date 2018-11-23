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

    string s;
    cin >> s;
    int len = s.length();

    int row = ceil((double) len / 20.0);
    int col = len / row;
    
    if (row * col == len) {
        cout << row << " " << col << endl;
        for (int i = 0; i < len; i += col) cout << s.substr(i, col) << endl;
    }
    else {
        cout << row << " " << col + 1 << endl;
        int diff = row - len % row;
        for (int i = 0; i < diff; i++) cout << setfill('*') << setw(col + 1) << s.substr(i * col, col) << endl;
        int sofar = diff * col;
        for (int i = 0; i < (row - diff); i++) cout << s.substr(sofar + i * (col + 1), col + 1) << endl;
    }
}

/*
USE LONG LONG!!!!
*/