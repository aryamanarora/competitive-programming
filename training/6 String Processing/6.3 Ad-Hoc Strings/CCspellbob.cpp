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

    int n;
    cin >> n;
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        bool bob = false;
        for (int j = 0; j < 8 and !bob; j++) {
            string pos = bitset<3>(j).to_string();
            for (int k = 0; k < 3; k++) {
                if (pos[k] == '1') swap(a[k], b[k]);
            }
            string a_sort(a), b_sort(b);
            sort(a_sort.begin(), a_sort.end());
            sort(b_sort.begin(), b_sort.end());
            if (a_sort == "bbo" or b_sort == "bbo") bob = true;
            for (int k = 0; k < 3; k++) {
                if (pos[k] == '1') swap(a[k], b[k]);
            }
        }
        if (bob) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}