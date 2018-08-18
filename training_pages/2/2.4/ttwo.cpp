/*
ID: aryaman4
TASK: ttwo
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

    map<char, char> turn = {
        {'N', 'E'},
        {'E', 'S'},
        {'S', 'W'},
        {'W', 'N'},
    };

    ifstream fin("ttwo.in");
    char grid[10][10];
    ii cow, john;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fin >> grid[i][j];
            if (grid[i][j] == 'C') cow = mp(i, j);
            else if (grid[i][j] == 'F') john = mp(i, j);
        }
    }

    ofstream fout("ttwo.out");
    char dir_cow = 'N', dir_john = 'N';
    for (int i = 1; i < 160000; i++) {
        if (cow == john) {
            fout << i - 1 << endl;
            return 0;
        }

        if (dir_cow == 'N') {
            if (cow.f == 0 or grid[cow.f-1][cow.s] == '*') dir_cow = turn[dir_cow];
            else cow.f--;
        }
        else if (dir_cow == 'E') {
            if (cow.s == 9 or grid[cow.f][cow.s+1] == '*') dir_cow = turn[dir_cow];
            else cow.s++;
        }
        else if (dir_cow == 'S') {
            if (cow.f == 9 or grid[cow.f+1][cow.s] == '*') dir_cow = turn[dir_cow];
            else cow.f++;
        }
        else {
            if (cow.s == 0 or grid[cow.f][cow.s-1] == '*') dir_cow = turn[dir_cow];
            else cow.s--;
        }

        if (dir_john == 'N') {
            if (john.f == 0 or grid[john.f-1][john.s] == '*') dir_john = turn[dir_john];
            else john.f--;
        }
        else if (dir_john == 'E') {
            if (john.s == 9 or grid[john.f][john.s+1] == '*') dir_john = turn[dir_john];
            else john.s++;
        }
        else if (dir_john == 'S') {
            if (john.f == 9 or grid[john.f+1][john.s] == '*') dir_john = turn[dir_john];
            else john.f++;
        }
        else {
            if (john.s == 0 or grid[john.f][john.s-1] == '*') dir_john = turn[dir_john];
            else john.s--;
        }
    }
    fout << 0 << endl;
}