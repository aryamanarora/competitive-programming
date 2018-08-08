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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    multiset<int> a;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.insert(x);
    }

    multiset<int> b;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        
        auto itr = a.find(x);
        a.erase(itr);
        
        b.insert(x);
    }

    for (auto m : a) cout << m << endl;

    for (int i = 0; i < n - 2; i++) {
        cin >> x;
        
        auto itr = b.find(x);
        b.erase(itr);
    }

    for (auto m : b) cout << m << endl;
}