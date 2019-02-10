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

struct node {
    char v;
    node *a, *b, *c;
    node(char u) : v(u), a(nullptr), b(nullptr), c(nullptr) {};
    node* next(char u) {
        if (u == 'a') return a;
        else if (u == 'b') return b;
        else return c;
    }
};

struct trie {
    node* head;
    trie() {
        head = new node('x');
    };
    void insert(string s) {
        node* cur = head;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                if (cur->a == nullptr) cur->a = new node('a');
                cur = cur->a;
            }
            else if (s[i] == 'b') {
                if (cur->b == nullptr) cur->b = new node('b');
                cur = cur->b;
            }
            else {
                if (cur->c == nullptr) cur->c = new node('c');
                cur = cur->c;
            }
        }
        cur = nullptr;
    }
    bool count(string &s, bool changed, int pos, node* cur) {
        if (cur == nullptr) return false;
        // cout << s << " " << changed << " " << pos << " " << cur->v << endl;
        if (pos == s.length() - 1) {
            if (!changed) {
                if (s[pos] == 'a') {
                    if (cur->b != nullptr or cur->c != nullptr) return true;
                }
                else if (s[pos] == 'b') {
                    if (cur->a != nullptr or cur->c != nullptr) return true;
                }
                else if (cur->a != nullptr or cur->b != nullptr) return true;
                return false;
            }
            else if (cur->next(s[pos]) != nullptr) return true;
            else return false;
        }
        
        if (changed) return count(s, true, pos + 1, cur->next(s[pos]));
        bool res = false;
        for (char c = 'a'; c <= 'c'; c++) {
            if (c == s[pos]) continue;
            res |= count(s, true, pos + 1, cur->next(c));
        }
        res |= count(s, false, pos + 1, cur->next(s[pos]));
        return res;
    }
    bool count(string &s) {
        return count(s, false, 0, head);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    trie a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.insert(s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        bool res = a.count(s);
        cout << (res ? "YES" : "NO") << endl;
    }
}

/*
USE LONG LONG!!!!

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