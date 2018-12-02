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

struct node {
    char a;
    set<int> strs;
    map<char, node*> c;
    node(char x) : a(x) {};
};

struct suffix_trie {
    node* head;
    suffix_trie() {
        head = new node(' ');
    }
    void insert(const string s, int n) {
        node *cur = head;
        for (auto x : s) {
            if (!cur->c.count(x)) {
                cur->c[x] = new node(x);
            }
            cur->c[x]->strs.insert(n);
            cur = cur->c[x];
        }
        if (s.length() > 1) insert(s.substr(1), n);
    }
    ii find(const string s) {
        node *cur = head;
        for (auto x : s) {
            if (!cur->c.count(x)) {
                return {0, -1};
            }
            cur = cur->c[x];
        }
        return {cur->strs.size(), *(cur->strs.begin())};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    suffix_trie trie;
    vector<string> a(n);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a[i] = s;
        trie.insert(s, i);
    }

    cin >> n;
    while (n--) {
        cin >> s;
        ii ans = trie.find(s);
        cout << ans.f << " " << (ans.s == -1 ? "-" : a[ans.s]) << endl;
    }
}

/*
USE LONG LONG!!!!
*/