/*
ID: aryaman4
TASK: contact
LANG: C++14
*/

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("contact.in");
    ofstream fout("contact.out");

    string s, add;
    int a, b, n, len;
    fin >> a >> b >> n;
    while (fin >> add) s += add;
    len = s.length();

    auto cmp = [](const auto &a, const auto &b) {
        if (a.f.length() == b.f.length()) {
            return a.s.size() > b.s.size();
        }
        return a.f.length() < b.f.length();
    };
    priority_queue<pair<string, vi>, vector<pair<string, vi>>, decltype(cmp)> q(cmp);

    vector<pair<int, string>> ans;

    vi ones, zeroes;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') ones.pb(i);
        else zeroes.pb(i);
    }
    if (ones.size() > 0) q.push(mp("1", ones));
    if (zeroes.size() > 0) q.push(mp("0", zeroes));

    while (!q.empty()) {
        auto x = q.top();
        q.pop();
        if (x.f.length() <= b) {
            if (x.f.length() >= a) ans.pb(mp(x.s.size(), x.f));
            map<char, vi> ins;
            for (auto &y : x.s) {
                if (y < len - 1) ins[s[y + 1]].pb(y + 1);
            }
            for (auto &y : ins) q.push(mp(x.f + y.f, y.s));
        }
    }

    auto cmp2 = [](const auto &a, const auto &b) {
        if (a.f == b.f) {
            if (a.s.length() == b.s.length()) return a.s < b.s;
            return a.s.length() < b.s.length();
        }
        return a.f > b.f;
    };
    sort(ans.begin(), ans.end(), cmp2);

    int freq = -1, ct = 0, ctfreq = 0;
    for (auto &x : ans) {
        if (x.f != freq) {
            ctfreq = 0;
            ct++;
            if (ct == n + 1) break;
            if (freq != -1) fout << endl;
            freq = x.f;
            fout << freq << endl;
            fout << x.s;
        }
        else {
            if (ctfreq % 6 == 0) fout << endl; 
            else fout << " ";
            fout << x.s;
        }
        ctfreq++;
    }
    fout << endl;

    fin.close();
    fout.close();
}