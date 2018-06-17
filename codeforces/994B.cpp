#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Knight {
    long long id_, power_, coins_;
};

void out (Knight x) {
    cout << x.coins_<< " ";
};

int main () {
    long long n, k;
    cin >> n >> k;

    vector<Knight> kn;

    long long power[n], coins[n];
    for (long long i = 0; i < n; i++) {
        cin >> power[i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (long long i = 0; i < n; i++) {
        Knight x;
        x.id_ = i;
        x.power_ = power[i];
        x.coins_ = coins[i];
        kn.push_back(x);
    }

    sort(begin(kn), end(kn), [](const Knight& a, const Knight& b)
    {
        return a.power_ > b.power_;
    });
    vector<Knight> t = kn;

    long long ans[n];
    for (int i = 0; i < n; i++) {
        sort(begin(kn)+i+1, end(kn), [](const Knight& a, const Knight& b)
        {
            return a.coins_ > b.coins_;
        });
        for (int j = i; j < i + k && j < n; j++) {
            kn[i].coins_ += kn[j].coins_;
        }
        
        ans[kn[i].id_] = kn[i].coins_;
        sort(begin(kn)+i+1, end(kn), [](const Knight& a, const Knight& b)
        {
            return a.power_ > b.power_;
        });
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}