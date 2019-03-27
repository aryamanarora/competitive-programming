#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    ll oldn = n;
    ll sum = (n * (n + 1)) / 2;
    if (sum % 2 == 1) {
        cout << "NO" << '\n';
        return 0;
    }

    int ans[n];
    sum /= 2;
    int pos = 0;
    while (sum > 0) {
        if (sum > n) {
            sum -= n;
            ans[pos] = n;
            n--;
        }
        else {
            ans[pos] = sum;
            sum = 0;
        }
        pos++;
    }

    cout << "YES" << '\n';
    cout << pos << '\n';
    for (int i = 0; i < pos; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    cout << oldn - pos << '\n';
    for (int i = oldn, j = 0; i >= 1; i--) {
        if (i == ans[j]) j++;
        else cout << i << " ";
    }
    cout << '\n';
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