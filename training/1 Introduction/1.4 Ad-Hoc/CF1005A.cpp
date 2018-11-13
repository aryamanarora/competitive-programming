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
    int n;
    cin >> n;
    int count = 0;
    vi length;
    int current_length = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            if (current_length != 0) length.pb(current_length);
            current_length = 1;
            count++;
        }
        else {
            current_length++;
        }
    }
    length.pb(current_length);
    cout << count << "\n";
    for (auto x : length) cout << x << " ";
    cout << "\n";
}