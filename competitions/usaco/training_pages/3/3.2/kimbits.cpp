/*
ID: aryaman4
TASK: kimbits
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

struct seq {
    int seq;
    int ones, len;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");

    int n, l, i;
    fin >> n >> l >> i;
    if (i == 1) {
        fout << string(n, '0') << endl;
        return 0;
    }

    queue<seq> q;
    q.push({1, 1, 1});
    int pos = 1; seq cur;

    while (!q.empty()) {
        try {
            cur = q.front();
            q.pop();
            pos++;
            if (pos == i) {
                string a = bitset<32>(cur.seq).to_string();
                for (int i = 32 - n; i < 32; i++) fout << a[i];
                fout << endl;
                return 0;
            }
            if (cur.len < n) {
                q.push({(cur.seq << 1), cur.ones, cur.len + 1});
                if (cur.ones < l) q.push({(cur.seq << 1) + 1, cur.ones + 1, cur.len + 1});
            }
        }
        catch (exception &e) {
            cout << q.size() << endl << e.what() << endl;
        }
    }

    fin.close();
    fout.close();
}