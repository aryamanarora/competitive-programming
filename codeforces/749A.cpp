#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int l = (int) n / 2;
    cout << l << endl;

    for (int i = 0; i < l; i++) {

        if (i == l - 1) {
            if (n % 2 == 1) {
                cout << "3" << endl;
            }
            else {
                cout << "2" << endl;
            }
        }
        else {
            cout << "2 ";
        }
    }
}