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

void solve() {
    string s;
    cin >> s;
    stack<char> bag;
    for (auto x : s) {
        if (x == '$' or x == '|' or x == '*') bag.push(x);
        else if (x == 'b') {
            if (bag.size() == 0) {
                cout << "NO" << endl;
                return;
            }
            if (bag.top() == '$') bag.pop();
            else {
                cout << "NO" << endl;
                return;
            }
        }
        else if (x == 't') {
            if (bag.size() == 0) {
                cout << "NO" << endl;
                return;
            }
            if (bag.top() == '|') bag.pop();
            else {
                cout << "NO" << endl;
                return;
            }
        }
        else if (x == 'j') {
            if (bag.size() == 0) {
                cout << "NO" << endl;
                return;
            }
            if (bag.top() == '*') bag.pop();
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (bag.size() != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) solve();
}

/*
USE LONG LONG!!!!
*/