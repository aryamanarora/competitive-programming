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
    
    int n = 0;
    while (cin >> n) {
        vi arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        vi diffs(arr.size());
        for (int i = 1; i < arr.size(); i++) diffs[i] = abs(arr[i] - arr[i - 1]);
        sort(diffs.begin(), diffs.end());

        bool jolly = true;
        for (int i = 1; i < diffs.size(); i++) {
            if (diffs[i] != i) {
                jolly = false;
                break;
            }
        }

        cout << (jolly ? "Jolly" : "Not jolly") << endl;
    }
}