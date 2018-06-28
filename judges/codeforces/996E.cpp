#include <iostream>
#include <vector>

using namespace std;

struct Vector {
    int id;
    double x, y;
};

int main() {
    int n;
    cin >> n;

    Vector p;
    p.x = 0.0;
    p.y = 0.0;

    vector<Vector> moves;
    for (int i = 0; i < n; i++) {
        Vector a;
        cin >> a.x >> a.y;
        a.id = i;
        moves.push_back(a);
    }

    sort(moves.begin(), moves.end());
    
}