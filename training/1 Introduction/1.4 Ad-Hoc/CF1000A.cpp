#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <map>

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
    int n;
    cin >> n;
    map<string, int> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[s]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[s]--;
    }
    for (auto x : a) ans += abs(x.s);
    cout << ans / 2 << "\n";
}