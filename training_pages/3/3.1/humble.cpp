/*
ID: aryaman4
TASK: inflate
LANG: C++14
*/

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

    ifstream fin("humble.in");
    ofstream fout("humble.out");

    int k = 0, n;
    fin >> k >> n;
    vi primes(k);
    for (int i = 0; i < k; i++) fin >> primes[i];
}