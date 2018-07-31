#include <iostream>
#include <string>

using namespace std;

int main() {
  int x = 0;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    if (a.find("++") != string::npos) {
      x++;
    }
    else {
      x--;
    }
  }

  cout << x << endl;
}
