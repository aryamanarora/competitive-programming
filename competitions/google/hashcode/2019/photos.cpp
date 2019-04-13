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

void solve(string a, string b) {
    ifstream cin(a);
    ofstream cout(b);

    int n;
    cin >> n;

    vi h, v;
    vector<set<string>> k(n);
    for (int i = 0; i < n; i++) {
        char a; int m;
        cin >> a >> m;
        string s;
        for (int j = 0; j < m; j++) {
            cin >> s;
            k[i].insert(s);
        }
        if (a == 'H') h.push_back(i);
        else v.push_back(i);
    }

    shuffle(v.begin(), v.end(), rng);

    vii pics;
    for (auto &x : h) pics.push_back({x, -1});
    for (int i = 1; i < v.size(); i += 2) {
        pics.push_back(mp(v[i], v[i - 1]));
    }

    shuffle(pics.begin(), pics.end(), rng);

    deque<ii> ans;
    set<string> cur, left, right;
    ans.push_back(pics.back());
    if (ans.back().s != -1) {
        for (auto &x : k[ans.back().f]) left.insert(x);
        for (auto &x : k[ans.back().s]) left.insert(x);
    }
    else left = k[ans.back().f];
    pics.pop_back();
    right = left;
    ll anss = 0;
    for (auto &x : pics) {
        // if (ans.size() % 1000 == 0) cerr << ans.size() << endl;
        cur.clear();
        if (x.s != -1) {
            for (auto &x : k[x.f]) cur.insert(x);
            for (auto &x : k[x.s]) cur.insert(x);
        }
        else cur = k[x.f];

        int res1 = 0, res1a = 0, res1b = 0;
        for (auto &x : cur) {
            if (left.count(x)) res1++;
            else res1a++;
        }
        for (auto &x : left) if (!cur.count(x)) res1b++;
        res1 = min(res1, min(res1a, res1b));

        int res2 = 0, res2a = 0, res2b = 0;
        for (auto &x : cur) {
            if (right.count(x)) res2++;
            else res2a++;
        }
        for (auto &x : right) if (!cur.count(x)) res2b++;
        res2 = min(res2, min(res2a, res2b));

        if (res1 > res2) {
            left = cur;
            ans.push_front(x);
            anss += res1;
        }
        else {
            right = cur;
            ans.push_back(x);
            anss += res2;
        }
    }

    cerr << anss << endl;

    cout << ans.size() << endl;
    for (auto &x : ans) {
        if (x.s == -1) cout << x.f << endl;
        else cout << x.f << " " << x.s << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> files = {
        "a_example.txt",
        "b_lovely_landscapes.txt",
        "c_memorable_moments.txt",
        "d_pet_pictures.txt",
        "e_shiny_selfies.txt"
    };

    for (auto &x : files) {
        solve(x, "t" + string(1, x[0]) + ".out");
    }
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