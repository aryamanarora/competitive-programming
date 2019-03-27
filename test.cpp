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

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cout << "Number of black alleles: ";
    cin >> a;
    cout << endl;
    cout << "Number of brown alleles: ";
    cin >> b;
    cout << endl;

    vector<int> genes;
    for (int i = 0; i < a; i++) genes.push_back(1);
    for (int i = 0; i < b; i++) genes.push_back(2);
    shuffle(genes.begin(), genes.end(), rng);

    uniform_int_distribution<> gen(0, a + b);

    int BB = 0, Bb = 0, bb = 0;
    for (int i = 0; i < 50; i++) {
        int x = gen(rng), y = gen(rng);
        if (genes[x] == 1 and genes[y] == 1) BB++;
        else if (genes[x] == 2 and genes[y] == 2) bb++;
        else Bb++;
    }

    cout << "2 black: " << BB << endl;
    cout << "1 black 1 brown: " << Bb << endl;
    cout << "2 brown: " << bb << endl;
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:
:pray: :prodakcin:

          .=     ,        =.
  _  _   /'/    )\,/,/(_   \ \
   `//-.|  (  ,\\)\//\)\/_  ) |
   //___\   `\\\/\\/\/\\///'  /
,-"~`-._ `"--'_   `"""`  _ \`'"~-,_
\       `-.  '_`.      .'_` \ ,-"~`/
 `.__.-'`/   (-\        /-) |-.__,'
   ||   |     \O)  /^\ (O/  | .        <-  BESSIE THE COW
   `\\  |         /   `\    /
     \\  \       /      `\ /
      `\\ `-.  /' .---.--.\
        `\\/`~(, '()      ('
         /(O) \\   _,.-.,_)    
        //  \\ `\'`      /
       / |  ||   `""""~"`
     /'  |__||
           `o
*/