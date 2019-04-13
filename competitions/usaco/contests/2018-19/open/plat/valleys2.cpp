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

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

template<size_t S>
struct linkcut {
	int p[S+1], pp[S+1], c[S+1][2];
	bool f[S+1];
	int ci(int u) {
		return c[p[u]][1]==u;
	}
	void cn(int u, int v, int i) {
		if(u)
			p[u]=v;
		if(v)
			c[v][i]=u;
	}
	void ro(int u) {
		int v=p[u], w=p[v], i=ci(u), j=ci(v);
		cn(c[u][!i], v, i);
		cn(v, u, !i);
		cn(u, w, j);
		swap(pp[u], pp[v]);
	}
	int app(int u) {
		if(u) {
			f[u]^=1;
			swap(c[u][0], c[u][1]);
		}
		return u;
	}
	void psh(int u) {
		if(f[u]) {
			app(c[u][0]);
			app(c[u][1]);
			f[u]=0;
		}
	}
	void psha(int u) {
		if(!u)
			return;
		psha(p[u]);
		psh(u);
	}
	int spl(int u) {
		psha(u);
		while(p[p[u]]) {
			if(ci(u)==ci(p[u]))
				ro(p[u]);
			else
				ro(u);
			ro(u);
		}
		if(p[u])
			ro(u);
		return u;
	}
	void dc(int u, int i) {
		if(c[u][i]) {
			p[c[u][i]]=0;
			if(i)
				pp[c[u][i]]=u;
		}
		c[u][i]=0;
	}
	int xp(int u) {
		for(int v=0, w=u; w; v=w, w=pp[w]) {
			spl(w);
			dc(w, 1);
			cn(v, w, 1);
			pp[v]=0;
		}
		return spl(u);
	}
	int mr(int u) {
		return app(xp(u));
	}
	void lk(int u, int v) {
		pp[mr(u)]=v;
	}
	void ct(int u) {
		dc(xp(u), 0);
	}
	int bg(int u) {
		psh(u);
		return c[u][0]?bg(c[u][0]):spl(u);
	}
	int gr(int u) {
		return bg(xp(u));
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    linkcut<600000> lc;
    
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:
:pray: :prodakcin:

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