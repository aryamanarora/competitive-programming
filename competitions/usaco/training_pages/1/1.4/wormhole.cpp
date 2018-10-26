/*
ID: aryaman4
TASK: wormhole
LANG: C++11         
*/
// got stuck, had to see http://www.usaco.org/current/data/sol_wormhole.html

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, X[13], Y[13], partner[13], on_right[13];

bool cycle_exists() {
    for (int i = 1; i <= N; i++) {
        int pos = i;
        for (int j = 0; j < N; j++) {
            pos = on_right[partner[pos]];
        }
        if (pos != 0) return true;
    }
    return false;
}

int solve(void) {
    int i = 0, total = 0;
    for (i = 1; i <= N; i++) {
        if (partner[i] == 0) break;
    }

    if (i > N) {
        for (int x = 1; x <= N; x++) {
            cout << x << " " << partner[x] << "\n";
        }
        cout << "\n";
        if (cycle_exists()) return 1;
        else return 0;
    }

  for (int j=i+1; j<=N; j++)
    if (partner[j] == 0) {
      partner[i] = j;
      partner[j] = i;
      total += solve();
      partner[i] = partner[j] = 0;
    }
  return total;
}

int main(void) {
  ifstream fin("wormhole.in");
  fin >> N;
  for (int i=1; i<=N; i++) fin >> X[i] >> Y[i];
  fin.close();
  
  for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
      if (X[j] > X[i] && Y[i] == Y[j])
        if (on_right[i] == 0 || X[j]-X[i] < X[on_right[i]]-X[i])
	        on_right[i] = j;

  ofstream fout("wormhole.out");
  fout << solve() << "\n";
  fout.close();
  return 0;
}
