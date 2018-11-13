#include <iostream>

using namespace std;

int main() {
    string s;
    int quotes = 0;
    while (getline(cin, s))
    {
        for (auto x : s) {
            if (x == '"') {
                if (quotes % 2) cout << "''";
                else cout << "``";
                quotes++;
            }
            else cout << x;
        }
        cout << endl;
    }
}