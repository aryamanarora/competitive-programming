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

void caesar(char &x, int o) {
    if (x + o > 'z') {
        x = 'a' + (x + o) - 'z' - 1;
    }
    else {
        x += o;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

    int o, steps; string s;
    cin >> o >> s >> steps;
    int len = s.length();

    int v = 0;
    for (auto x : s) if (vowels.count(x)) v++;

    int good = 0, bad = 0;
    for (int i = 0; i < steps; i++) {
        for (int i = 0; i < len; i++) {
            bool isv = vowels.count(s[i]);
            caesar(s[i], o);
            if (!isv and vowels.count(s[i])) v++;
            else if (isv and !vowels.count(s[i])) v--;
        }
        if (v * 2 >= len - v) bad++;
        else good++;
        // cout << s << endl;
    }

    // cout << good << " " << bad << endl;
    if (good > bad) cout << "Boris" << endl;
    else cout << "Colleague" << endl;
}

/*
USE LONG LONG!!!!
*/