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

const ll MOD = 1000000007;

int dist(char a, char b) {
    return min(abs(a - b), min(abs(a - 'a') + abs(b - 'z'), abs(a - 'z') + abs(b - 'a')));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    string a;
    cin >> n >> p >> a;
}