/*
ID: aryaman4
TASK: preface
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <map>

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

string roman_numerals = "MDCLXVI";
map<char, int> key = {
    { 'M', 1000 },
    { 'D', 500 },
    { 'C', 100 },
    { 'L', 50 },
    { 'X', 10 },
    { 'V', 5 },
    { 'I', 1 },
};

string helper(int &n, const char rom) {
    int val = key[rom];
    string conv = "";
    if (to_string(val)[0] == '1') {
        while (n >= val) {
            n -= val;
            conv += rom;
        }
        if (conv.length() == 4) {
            conv = rom;
            conv += roman_numerals[roman_numerals.find(rom) - 1];
        }
    }
    else {
        if (n >= (val * 2) - (val / 5)) {
            n -= val * 2 - val / 5;
            conv += roman_numerals[roman_numerals.find(rom) + 1];
            conv += roman_numerals[roman_numerals.find(rom) - 1];
        }
        else if (n >= val) {
            n -= val;
            conv += rom;
        }
    }
    return conv;
}

string convert(int n) {
    string res = "";
    for (auto rom : roman_numerals) {
        res += helper(n, rom);
    }
    return res;
}

int main() {
    ifstream fin("preface.in");
    int n;
    fin >> n;
    fin.close();
    map<char, int> ans;

    for (int i = 1; i <= n; i++) {
        string conv = convert(i);
        for (auto a : conv)
        {
            ans[a]++;
        }
    }
    ofstream fout("preface.out");
    reverse(roman_numerals.begin(), roman_numerals.end());
    for (auto a : roman_numerals) {
        if (ans[a] > 0) {
            fout << a << " " << ans[a] << endl;
        }
    }
    fout.close();
}