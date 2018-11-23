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

    int n;
    cin >> n;
    map<string, int> key;
    key["void"] = 0;
    key["errtype"] = -1;
    string a, b, c;
    while (n--) {
        cin >> a;
        if (a == "typedef") {
            cin >> b >> c;
            int ptr = count(b.begin(), b.end(), '*');
            int deref = count(b.begin(), b.end(), '&');
            b.erase(remove(b.begin(), b.end(), '*'), b.end());
            b.erase(remove(b.begin(), b.end(), '&'), b.end());
            key[c] = (key[b] == -1 ? -1 : key[b] + ptr);
            key[c] = (key[c] == -1 ? -1 : key[c] - deref);
            if (key[c] < 0) key[c] = -1;
        }
        else {
            cin >> b;
            int ptr = count(b.begin(), b.end(), '*');
            int deref = count(b.begin(), b.end(), '&');
            b.erase(remove(b.begin(), b.end(), '*'), b.end());
            b.erase(remove(b.begin(), b.end(), '&'), b.end());
            if (key.count(b) == 0) {
                cout << "errtype" << endl;
                continue;
            }
            int ans = (key[b] == -1 ? -1 : key[b] + ptr);
            ans = (ans == -1 ? -1 : ans - deref);
            if (ans < 0) ans = -1;
            cout << (ans == -1 ? "errtype" : "void");
            for (int i = 0; i < ans; i++) cout << "*";
            cout << endl;
        }
    }
}

/*
USE LONG LONG!!!!
*/