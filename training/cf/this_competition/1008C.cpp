#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <map>
#include <regex>

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
    ll n = 0;
    cin >> n;
    map<ll, ll> arr;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr[x]++;
    }
    ll max_occurences = 0;
    for (auto x : arr) {
        if (x.s > max_occurences) max_occurences = x.s;
    }
    cout << n - max_occurences << "\n";
    return 0;
}