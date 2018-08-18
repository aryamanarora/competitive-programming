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

    int k = 0;
    string a;
    cin >> k >> a;
    int len = a.length();

    vi b(k);
    int empty = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == '?' and a[len-i-1] != '?') {
            a[i] = a[len-i-1];
        }
        if (a[i] - 'a' >= k or a[i] != a[len-i-1]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        if (a[i] == '?') empty++;
        b[a[i]]++;
    }
    list<char> ch;
    for (char i = 'a'; i < 'a' + k; i++) {
        if (b[i] == 0) ch.pb(i);
    }
    if (ch.size() * 2 > empty) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (a[i] == '?') {
            a[i] = a[len-i-1] = ch[0];
            ch.pop_front();
        }
    }
    cout << a << endl;
}