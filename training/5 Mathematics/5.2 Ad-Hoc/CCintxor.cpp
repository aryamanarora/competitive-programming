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

int query(int a, vi x) {
    cout << a << " ";
    for (auto y : x) cout << y << " ";
    cout << endl;
    cin >> x[0];
    return x[0];
}

/*
a: 1 2 3
b:   2 3 4
c:     3 4 5
d:       4 5 6
e:         5 6 7
f:           6 7 1
g:             7 1 2

1^4 = a^b
2^5 = b^c
3^6 = c^d
4^7 = d^e
5^1 = e^f
6^2 = f^g
7^3 = g^a

1^3^5 = a^b^c
2^4^6 = b^c^d
3^5^7 = c^d^e
4^6^1 = d^e^f
5^7^2 = e^f^g
6^1^3 = f^g^a
7^2^4 = g^a^b

1 = f^g^a^c^d
2 = g^a^b^d^e
3 = a^b^c^e^f
4 = b^c^d^f^g
5 = c^d^e^g^a
6 = d^e^f^a^b
7 = e^f^g^b^c
*/

array<int, 7> seven(int a) {
    array<int, 7> ans;
    int z = query(1, {a  , a+1, a+2});
    int b = query(1, {a+1, a+2, a+3});
    int c = query(1, {a+2, a+3, a+4});
    int d = query(1, {a+3, a+4, a+5});
    int e = query(1, {a+4, a+5, a+6});
    int f = query(1, {a+5, a+6, a  });
    int g = query(1, {a+6, a  , a+1});

    ans[0] = f^g^z^c^d;
    ans[1] = g^z^b^d^e;
    ans[2] = z^b^c^e^f;
    ans[3] = b^c^d^f^g;
    ans[4] = c^d^e^g^z;
    ans[5] = d^e^f^z^b;
    ans[6] = e^f^g^b^c;

    return ans;
}

/*
a: 1 2 3
b:   2 3 4
c:     3 4 5
d: 1     4 5
e: 1 2     5

1^4 = a^b
2^5 = b^c
3^1 = c^d
4^2 = d^e
5^3 = e^a

1^3^5 = a^b^c
2^4^1 = b^c^d
3^5^2 = c^d^e
4^1^3 = d^e^a
5^2^4 = e^a^b

1 = a^b^c^e^a = b^c^e
2 = a^b^b^c^d = a^c^d
3 = c^d^e^b^c = b^d^e
4 = d^e^a^c^d = a^c^e
5 = e^a^b^d^e = a^b^d
*/

array<int, 5> five(int a) {
    array<int, 5> ans;
    int z = query(1, {a  , a+1, a+2});
    int b = query(1, {a+1, a+2, a+3});
    int c = query(1, {a+2, a+3, a+4});
    int d = query(1, {a+3, a+4, a  });
    int e = query(1, {a+4, a  , a+1});

    ans[0] = b^c^e;
    ans[1] = z^c^d;
    ans[2] = b^d^e;
    ans[3] = z^c^e;
    ans[4] = z^b^d;

    return ans;
}

/*
a: 1 2 3
b: 1 2   4
c: 1   3 4
d:   2 3 4


1 = a^b^c
2 = a^b^d
3 = a^c^d
4 = b^c^d
*/

array<int, 4> four(int a) {
    array<int, 4> ans;
    int z = query(1, {a  , a+1, a+2});
    int b = query(1, {a  , a+1, a+3});
    int c = query(1, {a  , a+2, a+3});
    int d = query(1, {a+1, a+2, a+3});

    ans[0] = z^b^c;
    ans[1] = z^b^d;
    ans[2] = z^c^d;
    ans[3] = b^c^d;

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    
    if (n == 11) {
        for (int i = 0; i < n - 7;) {
            for (auto x : four(i + 1)) {
                a[i] = x;
                i++;
            }
        }
        for (int i = n - 7; i < n;) {
            for (auto x : seven(i + 1)) {
                a[i] = x;
                i++;
            }
        }
    }
    else if (n % 4 == 0) {
        for (int i = 0; i < n;) {
            for (auto x : four(i + 1)) {
                a[i] = x;
                i++;
            }
        }
    }
    else if (n % 4 == 1) {
        for (int i = 0; i < n - 5;) {
            for (auto x : four(i + 1)) {
                a[i] = x;
                i++;
            }
        }
        for (int i = n - 5; i < n;) {
            for (auto x : five(i + 1)) {
                a[i] = x;
                i++;
            }
        }
    }
    else if (n % 4 == 2) {
        for (int i = 0; i < n - 10;) {
            for (auto x : four(i + 1)) {
                a[i] = x;
                i++;
            }
        }
        for (int i = n - 10; i < n;) {
            for (auto x : five(i + 1)) {
                a[i] = x;
                i++;
            }
        }
    }
    else {
        for (int i = 0; i < n - 15;) {
            for (auto x : four(i + 1)) {
                a[i] = x;
                i++;
            }
        }
        for (int i = n - 15; i < n;) {
            for (auto x : five(i + 1)) {
                a[i] = x;
                i++;
            }
        }
    }

    if (query(2, a) == -1) exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}

/*
USE LONG LONG!!!!
*/