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

const vector<char> ranks = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'J', 'K', 'A'};
const vector<char> suits = {'C', 'D', 'H', 'S'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<char, char>>> a(n, vector<pair<char, char>>(m));
    set<pair<char, char>> cards;
    char p, q;
    ii j1_coord = {-1, -1}, j2_coord = {-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> p >> q;
            a[i][j] = {p, q};
            cards.insert({p, q});
            if (p == 'J') {
                if (q == '1') j1_coord = {i, j};
                else if (q == '2') j2_coord = {i, j};
            }
        }
    }

    vector<pair<ii, pair<bool, bool>>> ans;
    vector<set<pair<char, char>>> j1_p, j2_p;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            set<char> rank, suit;
            bool j1 = false, j2 = false;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    if (a[x][y] == mp('J', '1')) j1 = true;
                    else if (a[x][y] == mp('J', '2')) j2 = true;
                    else {
                        rank.insert(a[x][y].f);
                        suit.insert(a[x][y].s);
                    }
                }
            }

            set<pair<char, char>> j1_pp, j2_pp;
            bool found = false;
            if (rank.size() + j1 + j2 == 9) {
                if (j1 or j2) {
                    for (auto r : ranks) {
                        if (rank.count(r) == 0) {
                            for (auto s : suits) {
                                if (cards.count({r, s}) == 0) {
                                    found = true;
                                    if (j1) j1_pp.insert({r, s});
                                    if (j2) j2_pp.insert({r, s});
                                }
                            }
                        }
                    }
                }
                else found = true;
                if (found) {
                    ans.pb({{i, j}, {j1, j2}});
                    j1_p.pb(j1_pp);
                    j2_p.pb(j2_pp);
                }
            }
        }
    }

    int possible_ans = ans.size();
    if (possible_ans < 2) {
        cout << "No solution." << endl;
        return 0;
    }
    for (int i = 0; i < possible_ans; i++) {
        for (int j = i + 1; j < possible_ans; j++) {
            if (max(abs(ans[i].f.f - ans[j].f.f), abs(ans[i].f.s - ans[j].f.s)) >= 3) {
                char j1r = 'a', j1s = 'a', j2r = 'a', j2s = 'a';
                bool j1 = (ans[i].s.f or ans[j].s.f), j2 = (ans[i].s.s or ans[j].s.s);

                if (ans[i].s.f and ans[i].s.s) {
                    bool flag = false;
                    for (auto p : j1_p[i]) {
                        for (auto q : j2_p[i]) {
                            if (p.f != q.f) {
                                tie(j1r, j1s) = p;
                                tie(j2r, j2s) = q;
                                flag = true;
                                break;
                            }
                        }
                        if (flag) break;
                    }
                }
                else if (ans[i].s.f and ans[j].s.s) {
                    bool flag = false;
                    for (auto p : j1_p[i]) {
                        for (auto q : j2_p[j]) {
                            if (p.f != q.f) {
                                tie(j1r, j1s) = p;
                                tie(j2r, j2s) = q;
                                flag = true;
                                break;
                            }
                        }
                        if (flag) break;
                    }
                }
                else if (ans[j].s.f and ans[i].s.s) {
                    bool flag = false;
                    for (auto p : j1_p[j]) {
                        for (auto q : j2_p[i]) {
                            if (p.f != q.f) {
                                tie(j1r, j1s) = p;
                                tie(j2r, j2s) = q;
                                flag = true;
                                break;
                            }
                        }
                        if (flag) break;
                    }
                }
                else if (ans[j].s.f and ans[j].s.s) {
                    bool flag = false;
                    for (auto p : j1_p[j]) {
                        for (auto q : j2_p[j]) {
                            if (p.f != q.f) {
                                tie(j1r, j1s) = p;
                                tie(j2r, j2s) = q;
                                flag = true;
                                break;
                            }
                        }
                        if (flag) break;
                    }
                }
                else if (ans[i].s.f) {
                    bool flag = false;
                    for (auto p : j1_p[i]) {
                        if (j2_coord != mp(-1, -1)) {
                            for (auto r : ranks) {
                                for (auto s : suits) {
                                    if (p.f != r and cards.count({r, s}) == 0) {
                                        tie(j1r, j1s) = p;
                                        tie(j2r, j2s) = {r, s};
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag) break;
                            }
                        }
                        else {
                            tie(j1r, j1s) = p;
                            break;
                        }
                        if (flag) break;
                    }
                }
                else if (ans[j].s.f) {
                    bool flag = false;
                    for (auto p : j1_p[j]) {
                        if (j2_coord != mp(-1, -1)) {
                            for (auto r : ranks) {
                                for (auto s : suits) {
                                    if (p.f != r and cards.count({r, s}) == 0) {
                                        tie(j1r, j1s) = p;
                                        tie(j2r, j2s) = {r, s};
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag) break;
                            }
                        }
                        else {
                            tie(j1r, j1s) = p;
                            break;
                        }
                        if (flag) break;
                    }
                }
                else if (ans[i].s.s) {
                    bool flag = false;
                    for (auto p : j2_p[i]) {
                        if (j1_coord != mp(-1, -1)) {
                            for (auto r : ranks) {
                                for (auto s : suits) {
                                    if (p.f != r and cards.count({r, s}) == 0) {
                                        tie(j1r, j1s) = {r, s};
                                        tie(j2r, j2s) = p;
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag) break;
                            }
                        }
                        else {
                            tie(j2r, j2s) = p;
                            break;
                        }
                        if (flag) break;
                    }
                }
                else if (ans[j].s.s) {
                    bool flag = false;
                    for (auto p : j2_p[j]) {
                        if (j1_coord != mp(-1, -1)) {
                            for (auto r : ranks) {
                                for (auto s : suits) {
                                    if (p.f != r and cards.count({r, s}) == 0) {
                                        tie(j1r, j1s) = {r, s};
                                        tie(j2r, j2s) = p;
                                        flag = true;
                                        break;
                                    }
                                }
                                if (flag) break;
                            }
                        }
                        else {
                            tie(j2r, j2s) = p;
                            break;
                        }
                        if (flag) break;
                    }
                }
                else {
                    if (j1_coord != mp(-1, -1)) {
                        bool flag = false;
                        for (auto r : ranks) {
                            for (auto s : suits) {
                                if (cards.count({r, s}) == 0) {
                                    tie(j1r, j1s) = {r, s};
                                    cards.insert({r, s});
                                    flag = true;
                                    break;
                                }
                            }
                            if (flag) break;
                        }
                    }
                    if (j2_coord != mp(-1, -1)) {
                        bool flag = false;
                        for (auto r : ranks) {
                            for (auto s : suits) {
                                if (cards.count({r, s}) == 0) {
                                    tie(j2r, j2s) = {r, s};
                                    flag = true;
                                    break;
                                }
                            }
                            if (flag) break;
                        }
                    }
                }
                if (j1_coord != mp(-1, -1) and j1r == 'a') continue;
                if (j2_coord != mp(-1, -1) and j2r == 'a') continue;
                if (j1r != 'a') j1 = true;
                if (j2r != 'a') j2 = true;

                cout << "Solution exists." << endl;
                if (j1 + j2 == 0) cout << "There are no jokers." << endl;
                if (j1 and !j2) cout << "Replace J1 with " << j1r << j1s << "." << endl; 
                if (j2 and !j1) cout << "Replace J2 with " << j2r << j2s << "." << endl; 
                if (j1 and j2) cout << "Replace J1 with " << j1r << j1s << " and J2 with " << j2r << j2s << "." << endl;
                cout << "Put the first square to (" << ans[i].f.f + 1 << ", " << ans[i].f.s + 1 << ")." << endl;
                cout << "Put the second square to (" << ans[j].f.f + 1 << ", " << ans[j].f.s + 1 << ")." << endl;
                return 0;
            }
        }
    }
    cout << "No solution." << endl;
}
