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

bool right_hand(const char &c) {
    return (c == 'j' or c == 'k');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, w, ans, anss, len;
    string a;
    cin >> t;

    while (t--) {
        map<string, int> words;
        cin >> w;
        ans = 0;
        while (w--) {
            cin >> a;
            if (words.count(a)) {
                ans += (words[a] / 2);
                continue;
            }

            len = a.length();
            anss = 2;
            for (int i = 1; i < len; i++) {
                if (right_hand(a[i]) != right_hand(a[i-1])) anss += 2;
                else anss += 4;
            }

            words[a] = anss;
            ans += anss;
        }
        cout << ans << endl;
    }
}