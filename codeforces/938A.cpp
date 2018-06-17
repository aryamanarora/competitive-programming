#include <iostream>
#include <string>
#include <regex>

using namespace std;


int main () {
    int n;
    string s;
    string v = "aeiouy";
    cin >> n >> s;

    int vowel = 0;
    for (int i = 0; i < n; i++) {
        if (v.find(s[i]) == string::npos) {
            cout << s[i];
            vowel = 0;
        }
        else if (v.find(s[i]) != string::npos) {
            if (vowel == 0) {
                cout << s[i];
            }
            vowel++;
        }
    }
    cout << endl;
}