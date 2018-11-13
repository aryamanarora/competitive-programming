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

bool ends_with(string const &value, string const &ending)
{
    if (ending.size() > value.size()) return false;
    return equal(ending.rbegin(), ending.rend(), value.rbegin());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    map<string, set<string>> b;
    map<string, vector<string>> book;
    string s;
    int a;
    
    for (int i = 0; i < n; i++) {
        cin >> s >> a;
        string num;
        for (int j = 0; j < a; j++) {
            cin >> num;
            b[s].insert(num);
        }
    }

    vector<string> numss;
    for (auto &entry : b) {
        numss.assign(entry.s.begin(), entry.s.end());
        sort(numss.begin(), numss.end(), [](const auto &a, const auto &b) {
            return a.length() > b.length();
        });

        int ct = numss.size();
        for (int j = ct - 1; j >= 0; j--) {
            bool suffix = false;
            for (int k = j - 1; k >= 0 and !suffix; k--) {
                suffix = ends_with(numss[k], numss[j]);
            }
            if (!suffix) {
                book[entry.f].pb(numss[j]);
            }
        }
        
        numss.clear();
    }
    
    cout << book.size() << endl;
    for (auto &p : book) {
        cout << p.f << " " << p.s.size() << " ";
        for (auto &phone : p.s) {
            cout << phone << " ";
        }
        cout << endl;
    }
}