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

    int n, l, x, y, b;
    cin >> n >> l >> x >> y;
    set<int> a;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a.insert(b);
    }

    bool boy = false, girl = false;
    set<int> boys, girls;
    for (auto mark : a) {
        if (a.count(mark + x)) boy = true;
        else {
            if (mark + x <= l) boys.insert(mark + x);
            if (mark - x >= 0) boys.insert(mark - x);
        }
        if (a.count(mark + y)) girl = true;
        else {
            if (mark + y <= l) girls.insert(mark + y);
            if (mark - y >= 0) girls.insert(mark - y);
        }
        if (boy and girl) break;
    }

    if (boy and girl) cout << 0 << endl;
    else if (boy and !girl) cout << 1 << endl << *girls.begin() << endl;
    else if (girl and !boy) cout << 1 << endl << *boys.begin() << endl;
    else {
        for (auto b : boys) {
            if (girls.count(b)) {
                cout << 1 << endl << b << endl;
                return 0;
            }
        }
        cout << 2 << endl << *boys.begin() << " " << *girls.begin() << endl;
    }
}

/*
USE LONG LONG!!!!
*/