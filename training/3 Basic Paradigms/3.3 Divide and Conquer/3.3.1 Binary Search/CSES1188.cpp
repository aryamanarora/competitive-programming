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

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<pair<int, int>> r;
    multiset<int> l;
    string s;
    cin >> s;
    s += 'a';
    int start = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) {
            r.insert({i - 1, start});
            l.insert(i - start);
            start = i;
        }
    }

    auto rem = [&](pair<int, int> x) {
        // cout << "rem " << x.s << " " << x.f << endl;
        l.erase(l.find(x.f - x.s + 1));
        r.erase(x);
    };

    auto ins = [&](pair<int, int> x) {
        // cout << "ins " << x.s << " " << x.f << endl;
        l.insert(x.f - x.s + 1);
        r.insert(x);
    };

    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q, q--;
        auto it = r.lower_bound({q, 0});
        if (it->f == it->s) {
            if (it != r.begin() and it != prev(r.end())) {
                auto n = *next(it);
                auto p = *prev(it);
                rem(*it); rem(n); rem(p);
                ins({n.f, p.s});
            }
            else if (it == r.begin()) {
                auto n = *next(it);
                rem(*it); rem(n);
                ins({n.f, q});
            }
            else {
                auto p = *prev(it);
                rem(*it); rem(p);
                ins({q, p.s});
            }
        }
        else if (it->f == q) {
            if (it != prev(r.end())) {
                auto c = *it;
                auto n = *next(it);
                rem(*it); rem(n);
                ins({q - 1, c.s}); ins({n.f, q});
            }
            else {
                auto c = *it;
                rem(*it);
                ins({q - 1, c.s}); ins({q, q});
            }
        }
        else if (it->s == q) {
            if (it != r.begin()) {
                auto c = *it;
                auto p = *prev(it);
                rem(*it); rem(p);
                ins({q, p.s}); ins({c.f, q + 1});
            }
            else {
                auto c = *it;
                rem(*it);
                ins({c.f, q + 1}); ins({q, q});
            }
        }
        else {
            auto c = *it;
            rem(*it);
            ins({q - 1, c.s}); ins({q, q}); ins({c.f, q + 1});
        }
        cout << *(prev(l.end())) << " ";
    }
    cout << endl;
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