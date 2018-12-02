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
    int label, count;
    node *left, *right, *parent;
    node(int lb, int ct, node* p) : label(lb), count(ct), left(nullptr), right(nullptr), parent(p) {};
    node(int lb, int ct, node* p, node* l, node* r) : label(lb), count(ct), left(l), right(r), parent(p) {};
    node(int lb, int ct) : label(lb), count(ct), left(nullptr), right(nullptr), parent(nullptr) {};
    node() : label(0), count(0), left(nullptr), right(nullptr), parent(nullptr) {};
};

struct cartesian_tree {
    int n;
    node* head, *last;
    vi left, right;
    cartesian_tree(int N, vi &a) : n(N), left(N), right(N) {
        build(a);
    };
    void build(vi &a) {
        for (int i = 0; i < n; i++) {
            // cout << a[i] << endl;
            if (i == 0) {
                head = new node(a[i], i);
                last = head;
            }
            else if (last->label < a[i]) {
                last->right = new node(a[i], i, last);
                last = last->right;
            }
            else {
                node* cur = last;
                while (cur->label > a[i]) {
                    cur = cur->parent;
                    if (cur == nullptr) break;
                }
                if (cur == nullptr) {
                    head = new node(a[i], i, nullptr, head, nullptr);
                    head->left->parent = head;
                    last = head;
                }
                else {
                    cur->right = new node(a[i], i, cur, cur->right, nullptr);
                    cur->right->left->parent = cur->right;
                    last = cur->right;
                }
                cur = nullptr;
            }
        }
        traverse(head);
        cout << head->label << endl;
    }
    int traverse(node *u) {
        if (u->left != nullptr) {
            cout << u->label << " left " << u->left->label << endl;
            left[u->count] += traverse(u->left);
        }
        if (u->right != nullptr) {
            cout << u->label << " right " << u->right->label << endl;
            right[u->count] += traverse(u->right);
        }
        return left[u->count] + 1;
    }
};