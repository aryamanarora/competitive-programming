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

    ifstream cin("cowmpatibility.in");
    ofstream cout("cowmpatibility.out");

    map<array<int, 2>, int> twos;
    map<array<int, 3>, int> threes;
    map<array<int, 4>, int> fours;
    map<array<int, 5>, int> fives;

    int n;
    cin >> n;

    array<int, 5> cur;
    for (int i = 0; i < n; i++) {
        for (auto &x : cur) cin >> x;
        sort(cur.begin(), cur.end());
        for (int i = 0; i < 5; i++)
            for (int j = i + 1; j < 5; j++) twos[{i, j}]++;
        for (int i = 0; i < 5; i++)
            for (int j = i + 1; j < 5; j++)
                for (int k = j + 1; k < 5; k++) threes[{i, j, k}]++;
        for (int i = 0; i < 5; i++)
            for (int j = i + 1; j < 5; j++)
                for (int k = j + 1; k < 5; k++) threes[{i, j, k}]++;
    }
}

/*
USE LONG LONG!!!!

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

1 2 3 4 5 6 7 8 9
1 2 3 4 5|6 7 8 9
*/

