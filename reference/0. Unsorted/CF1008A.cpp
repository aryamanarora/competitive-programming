#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

bool is_vowel(char a) {
    if (a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u') return true;
    else return false;
}

int main() {
    string a;
    cin >> a;
    bool word = true;
    for (int i = 0; i < a.length() - 1; i++) {
        if (!is_vowel(a[i])) {
            // there has to be a vowel after every consonant
            // only exception is a consonant "n"; after this letter,
            // there can be any letter (not only a vowel) or there can be no letter at all
            if (a[i] != 'n' and !is_vowel(a[i+1])) {
                word = false;
                break;
            }
        }
    }
    if (!is_vowel(a[a.length() - 1]) and a[a.length() - 1] != 'n') {
        word = false;
    }

    cout << (word ? "YES\n" : "NO\n");
}