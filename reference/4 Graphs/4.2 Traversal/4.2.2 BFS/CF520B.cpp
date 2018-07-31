#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <bitset>

using namespace std;

int main() {
    int ans = 0;
    int n, m;
    cin >> n >> m;
    queue<int> bfs;
    bfs.push(n);

    if (n >= m) {
        ans = n - m;
    }
    else {
        int traversed = 0;
        while (!bfs.empty()) {
            int x = bfs.front();
            bfs.pop();
            traversed++;
            if (x == m) {
                for (int i = 1; traversed > 0; i *= 2) {
                    traversed -= i;
                    ans++;
                }
                ans--;
                break;
            }
            bfs.push(x * 2);
            bfs.push(x - 1);
        }
    }

    cout << ans << "\n";
}