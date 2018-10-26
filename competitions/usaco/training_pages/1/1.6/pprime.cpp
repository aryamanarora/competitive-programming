/*
ID: aryaman4
TASK: pprime
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

vector<long long> pals = {1, 3, 5, 7, 9};

bool is_prime (long long x)
{
    bool prime;
    if (x <= 1) return false;
    else if (x == 2) return true;
    else {
        prime = true;
        long long lim = static_cast<long long> (sqrt(static_cast<double> (x)) + 1);
        
        for (long long d = 3; d <= lim; d += 2) {
            if (x % d == 0) return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("pprime.in");
    long long a, b;
    fin >> a >> b;

    for (int i = 1; i <= 9; i += 2)
        pals.push_back(i * 11);
    for (int i = 1; i <= 9; i += 2)
        for (int j = 0; j <= 9; j++)
            pals.push_back(i * 101 + j * 10);
    for (int i = 1; i <= 9; i += 2)
        for (int j = 0; j <= 9; j++)
            pals.push_back(i * 1001 + j * 110);
    for (int i = 1; i <= 9; i += 2)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                pals.push_back(i * 10001 + j * 1010 + k * 100);
    for (int i = 1; i <= 9; i += 2)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                pals.push_back(i * 100001 + j * 10010 + k * 1100);
    for (int i = 1; i <= 9; i += 2)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int l = 0; l <= 9; l++)
                    pals.push_back(i * 1000001 + j * 100010 + k * 10100 + l * 1000);
    for (int i = 1; i <= 9; i += 2)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int l = 0; l <= 9; l++)
                    pals.push_back(i * 10000001 + j * 1000010 + k * 100100 + l * 11000);
    for (int i = 1; i <= 9; i += 2)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int l = 0; l <= 9; l++)
                    for (int m = 0; m <= 9; m++)
                        pals.push_back(i * 100000001 + j * 10000010 + k * 1000100 + l * 101000 + m * 10000);
    
    

    ofstream fout("pprime.out");
    for (auto x : pals) {
        if (a <= x and x <= b) {
            if (is_prime(x)) fout << x << "\n";
        }
    }
    
}