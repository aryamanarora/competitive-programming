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

    int n, p, m;
    cin >> n >> p >> m;

    vi score(n, 0); string s;
    map<string, int> key;
    for (int i = 0; i < n; i++) {
        cin >> s;
        key[s] = i;
    }

    int a;
    vector<bool> won(n, false);
    int winct = 0;
    for (int i = 0; i < m; i++) {
        cin >> s >> a;
        score[key[s]] += a;
        if (score[key[s]] >= p and !won[key[s]]) {
            won[key[s]] = true;
            winct++;
            cout << s << " wins!" << endl;
        }
    }

    if (winct == 0) cout << "No winner!" << endl;
}

/*
USE LONG LONG!!!!
*/