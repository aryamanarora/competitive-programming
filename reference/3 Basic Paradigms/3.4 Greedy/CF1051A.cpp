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
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        vi ct(3);
        for (auto &c : s) {
            if (isupper(c)) ct[0]++;
            else if (islower(c)) ct[1]++;
            else ct[2]++;
        }
        if (ct[0] == 0 and ct[1] == 0) {
            s[0] = 'A'; s[1] = 'a';
        }
        else if (ct[0] == 0 and ct[2] == 0) {
            s[0] = 'A'; s[1] = '1';
        }
        else if (ct[1] == 0 and ct[2] == 0) {
            s[0] = 'a'; s[1] = '1';
        }
        else if (ct[0] == 0) {
            if (ct[1] == 1) {
                for (auto &c : s) {
                    if (isdigit(c)) {
                        c = 'A';
                        break;
                    }
                }
            }
            else if (ct[2] == 1) { 
                for (auto &c : s) {
                    if (islower(c)) {
                        c = 'A';
                        break;
                    }
                }
            }
            else s[0] = 'A';
        }
        else if (ct[1] == 0) {
            if (ct[0] == 1) {
                for (auto &c : s) {
                    if (isdigit(c)) {
                        c = 'a';
                        break;
                    }
                }
            }
            else if (ct[2] == 1) { 
                for (auto &c : s) {
                    if (isupper(c)) {
                        c = 'a';
                        break;
                    }
                }
            }
            else s[0] = 'a';
        }
        else if (ct[2] == 0) {
            if (ct[0] == 1) {
                for (auto &c : s) {
                    if (islower(c)) {
                        c = '1';
                        break;
                    }
                }
            }
            else if (ct[1] == 1) { 
                for (auto &c : s) {
                    if (isupper(c)) {
                        c = '1';
                        break;
                    }
                }
            }
            else s[0] = '1';
        }
        cout << s << endl;
    }
}