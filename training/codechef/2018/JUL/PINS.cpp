#include <bits/stdc++.h>
 
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
    int t = 0;
    cin >> t;
    vi n(t);
    for (int i = 0; i < t; i++) cin >> n[i];
 
    for (auto x : n) {
        int zeroes = x / 2;
        cout << "1 1"; 
        for (int i = 0; i < zeroes; i++) {
            cout << "0";
        }
        cout << "\n";
    }
}
 
/*
1 : 10 / 10
2 : 10 / 100
3 : 100 / 10^3
4 : 100 / 10^4
*/