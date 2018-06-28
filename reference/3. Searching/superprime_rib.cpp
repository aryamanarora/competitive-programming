/* A number is called superprime if it is prime and every number obtained by chopping some number of digits from the right side
of the decimal expansion is prime. For example, 233 is a superprime, because 233, 23, and 2 are all prime. Print a list of all
the superprime numbers of length n, for n <= 9. The number 1 is not a prime.

For this problem, use depth first search, since all the answers are going to be at the nth level (the bottom level) of the search. */

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<int> ans;
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
            ans.push_back(n);
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
}

int main() {
    cin >> target;
    if (target > 0) {
        for (int x = 0; x <= 9; x++) search(x);
    }
    for (auto x : ans) {
        cout << x << "\n";
    }
    return 0;
}
