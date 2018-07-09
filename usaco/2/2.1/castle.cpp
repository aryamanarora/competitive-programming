/*
ID: aryaman4
TASK: castle
LANG: C++14
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

vi components;
int s = 0;

struct Wall {
    int x, y, size;
    string direction;
};

int get_size(vi sizes, int a, int b) {
    if (components[a] != components[b])
        return sizes[components[a]] + sizes[components[b]];
    else
        return 0;
}

void flood_fill(int new_component, vector<vi> c) {
    int num;
    do {
        num = 0;
        for (int i = 0; i < s; i++) {
            if (components[i] == -2) {
                num++;
                components[i] = new_component;
                for (auto j : c[i]) {
                    if (components[j] == 0) components[j] = -2;
                }
            }
        }
    } while (num != 0);
}

void find_components(vector<vi> c) {
    int num = 0;
    for (int i = 0; i < s; i++) components.push_back(0);
    for (int i = 0; i < s; i++) {
        if (components[i] == 0) {
            num++;
            components[i] = -2;
            flood_fill(num, c);
        }
    }
}

int main() {
    ifstream fin("castle.in");
    int w, h;
    fin >> w >> h; // m is width, n is height
    s = w * h;
    vector<vi> c(w * h);

    for (int i = 0; i < w * h; i++) {
        int x;
        fin >> x;
        x = 15 - x;
        
        if (x >= 8) {
            x -= 8;
            c[i].pb(i + w);
        }
        if (x >= 4) {
            x -= 4;
            c[i].pb(i + 1);
        }
        if (x >= 2) {
            x -= 2;
            c[i].pb(i - w);
        }
        if (x >= 1) {
            x--;
            c[i].pb(i - 1);
        }
    } // make adjacency matrix

    find_components(c); // flood fill

    ofstream fout("castle.out");

    int num_components = *max_element(components.begin(), components.end());
    fout << num_components << "\n";

    vi sizes(num_components + 1);
    fill(sizes.begin(), sizes.end(), 0);
    for (int i = 0; i < s; i++) {
        sizes[components[i]]++;
    }
    fout << *max_element(sizes.begin(), sizes.end()) << "\n";

    Wall ans;
    ans.size = 0;
    for (int y = h - 1; y >= 0; y--) {
        for (int x = 0; x < w; x++) {
            int i = y * w + x; // position in adjacency matrix
            if (y != 0) {
                int a = get_size(sizes, i, i - w);
                if (a > ans.size) ans = {x + 1, y + 1, a, "N"};
            }
            if (x != w - 1) {
                int a = get_size(sizes, i, i + 1);
                if (a > ans.size) ans = {x + 1, y + 1, a, "E"};
            }
            if (x != 0) {
                int a = get_size(sizes, i, i - 1);
                if (a > ans.size) ans = {x + 1, y + 1, a, "W"};
            }
            if (y != h - 1) {
                int a = get_size(sizes, i, i + w);
                if (a > ans.size) ans = {x + 1, y + 1, a, "S"};
            }
        }
    }
    fout << ans.size << "\n" << ans.y << " " << ans.x << " " << ans.direction << "\n";
}