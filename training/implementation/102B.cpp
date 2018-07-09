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

int digit_sum(string n, int ans) {
    if (n.length() == 1) return ans;
    int sum = 0;
    for (char &x : n) {
        sum += x - '0';
    }
    
    if (sum < 10) return ans + 1;
    else return digit_sum(to_string(sum), ans + 1);
}

int main() {
    string n;
    cin >> n;
    int ans = digit_sum(n, 0);
    cout << ans << "\n";
}