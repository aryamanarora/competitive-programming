#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int ans = ((s[0] - '0') - 48), ct = 1;
    int pos = 0;
    for (int i = 0; (i < (s.length() - 1)) and (ct < k); i++) {
        if (i+1 > pos and s[i+1] - s[pos] >= 2) {
            ct++;
            ans += ((s[i+1] - '0') - 48);
            pos = i + 1;
        }
    }
    if (ct == k) {
        cout << ans << endl;
    }
    else {
        cout << "-1" << endl;
    }
}