#include <iostream>
#include <string>
using namespace std;

int main () {
  int m, n, ans;
  cin >> m >> n;

  if (m % 2 == 0 || n % 2 == 0) {
    ans = (m * n) / 2;
  }
  else {
    ans = ((m - 1) * n) / 2 + n / 2;
  }

  cout << ans << endl;
}
