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

inline namespace graph {
    struct unweighted_graph {
        unsigned long V; // vertices
        unsigned long E; // edges
        vector<vector<int>> list; // adjacency list

        unweighted_graph(int _V) {
            V = _V;
            list.resize(V + 1);
            E = 0;
        }
        virtual void add_edge(int i, int j) = 0;
        void add_vertices(int _V) {
            V += _V;
            list.resize(list.size() + _V);
        }
        bool is_edge(int i, int j) {
            if (find(list[i].begin(), list[i].end(), j) != list[i].end()) return true;
            else return false;
        }
    };
    struct undirected_unweighted_graph : public unweighted_graph {
        undirected_unweighted_graph(int _V) : unweighted_graph(_V) {
        }
        void add_edge(int i, int j) {
            list[i].push_back(j);
            list[j].push_back(i);
        }
    };

    struct directed_unweighted_graph : public unweighted_graph {
        directed_unweighted_graph(int _V) : unweighted_graph(_V) {
        }
        void add_edge(int i, int j) {
            list[i].push_back(j);
        }
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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