#include <bits/stdc++.h>

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int months, records;
    double down, loan;
    while (cin >> months >> down >> loan >> records) {
        if (months < 0) break;

        map<int, double> r;
        for (int i = 0; i < records; i++) {
            int a;
            double b;
            cin >> a >> b;
            r[a] = b;
        }

        double val = (loan + down) * (1.0 - r[0]);
        double deprec;
        double monthly_payment = loan / (double) months;
        int i;

        for (i = 1; i <= months and val <= loan; i++) {
            loan -= monthly_payment;
            if (r.find(i) != r.end()) deprec = r[i];
            val *= (1.0 - deprec);
        }
        cout << i - 1 << " " << ((i > 2) ? "months" : "month" ) << endl;
    }
}