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

    int n = 0, k;
    cin >> n >> k;
    string a;
    cin >> a;
    if (n == k) {
        cout << a << endl;
        return 0;
    }
    deque<char> pars;
    int oldn = n;
    for (int i = 0; i < oldn; i++) {
        pars.push_front(a[i]);
        if (pars.front() == ')' and n > k) {
            pars.pop_front();
            pars.pop_front();
            n -= 2;
        }
    }
    while (!pars.empty()) {
        cout << pars.back();
        pars.pop_back();
    }
    cout << endl;
}