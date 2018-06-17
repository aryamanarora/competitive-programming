#include <iostream>
#include <string>

using namespace std;

int main () {
    string x;
    cin >> x;

    int consec = 1;

    for (int i = 1; i < x.length(); i++) {
        if (x[i] == x[i - 1]) {
            consec++;
            if (consec > 7) {
                cout << "YES" << endl;
                return 0;
            }
        }
        else {
            consec = 1;
        }
    }
    cout << "NO" << endl;
    return 0;
}