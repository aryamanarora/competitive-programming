/*
ID: aryaman4
TASK: sprime
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
#include <string>

using namespace std;

set<int> ans;
int target;

bool is_prime (int n)
{
    bool prime;
    if (n <= 1) prime = false;
    else if (n == 2) prime = true;
    else if (n % 2 == 0) prime = false;
    else {
        prime = true;
        int lim = static_cast<int> (sqrt(static_cast<double> (n)) + 1);
        
        for (int d = 3; d <= lim; d += 2) {
            if (n % d == 0) prime = false;
        }
    }
    return prime;
}

int search(int n) {
    string s = to_string(n);
    if (s.length() == target) {
        if (is_prime(n)) {
            ans.insert(n);
            return 0;
        }
    }
    
    for (int x = 0; x <= 9; x++) {
        s.append(to_string(x));
        if (is_prime(stoi(s))) {
            search(stoi(s));
        }
        s.pop_back();
    }
    return 0;
}

int main() {
    ifstream fin("sprime.in");
    fin >> target;
    vector<int> primes = {2, 3, 5, 7};
    for (auto x : primes) search(x);
    ofstream fout("sprime.out");
    for (auto x : ans) {
        fout << x << "\n";
    }
    return 0;
}
