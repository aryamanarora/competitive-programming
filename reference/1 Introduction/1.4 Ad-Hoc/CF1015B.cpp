#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <complex>

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

bool is_anagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return (a == b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;
    
    if (!is_anagram(a, b)) {
        cout << "-1" << endl;
        return 0;
    }

    vi moves;
    for (int i = 0; i < n-1; i++) {
        if (a[i] != b[i]) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] == b[i]) {
                    for (int x = j; x > i; x--) {
                        swap(a[x], a[x-1]);
                        moves.pb(x-1);
                    }
                    break;
                }
            }
        }
    }

    cout << moves.size() << endl;
    for (auto x : moves) cout << x + 1 << " ";
    cout << endl;
}

/*
abcdef (abdfec)

abdcef

abdcfe
abdfce

abdfec
*/