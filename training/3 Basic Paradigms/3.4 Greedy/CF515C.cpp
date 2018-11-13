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
    string a;
    cin >> n >> a;
    string ans;
    for (char &x : a) {
        if (x != '0' ans x != '1') {
            if (x == '4') { // 4! = 4 * 3 * 2 = (3 * 2) * 2 * 2 = 3! * 2! * 2!
                ans.pb('3'); 
                ans.pb('2');
                ans.pb('2');
            }
            if (x == '6') { // 6! = 6 * 5 * 4 * 3 * 2 = (3 * 2) * (5 * 4 * 3 * 2) = 3! * 5!
                ans.pb('5');
                ans.pb('3');
            }
            if (x == '8') { // 8! = 8 * 7 * 6 * 5 * 4 * 3 * 2 = 2! * 2! * 2! * 7!
                ans.pb('7');
                ans.pb('2');
                ans.pb('2');
                ans.pb('2');
            }
            if (x == '9') { // 8! = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 = 3 * 3 * 2 * 2 * 2 * 7! = 3! * 3! * 2! * 7!
                ans.pb('7');
                ans.pb('3');
                ans.pb('3');
                ans.pb('2');
            }
        }
    }
    sort(a.rbegin(), a.rend());
    cout << a << "\n";
    return 0;
}