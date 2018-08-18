/*
ID: aryaman4
TASK: zerosum
LANG: C++14
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <complex>
#include <fstream>
#include <bitset>

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

void print(int n, ostream &os) {
    string num = to_string(n);
    for (int k = 0; k < num.size() - 1; k++) os << num[k] << " ";
    os << num[num.size()-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("zerosum.in");
    int n;
    fin >> n;
    fin.close();
    
    ofstream fout("zerosum.out");
    // first loop: uses bitmask to generate possible combinations of numbers
    // eg:
    // 1 2 3, 12 3, 1 23, 123
    // not optimized at all but given small bounds for n it is fine
    vector<string> ans;
    for (int x = 0; x < pow(2, n - 1); x++) {
        string merge = bitset<8>(x).to_string();
        reverse(merge.begin(), merge.end());
        vi nums;
        int current = 1;
        for (int i = 0; i < n - 1; i++) {
            if (merge[i] == '1') {
                current *= 10;
                current += i + 2;
            }
            else {
                nums.pb(current);
                current = i + 2;
            }
        }
        nums.pb(current);
        
        // second loop: uses bitmask to consider + and - of each combination
        for (int i = 0; i < pow(2, nums.size() - 1); i++) {
            int sum = nums[0];
            string pos = bitset<8>(i).to_string();
            reverse(pos.begin(), pos.end());
            for (int j = 1; j < nums.size(); j++) {
                if (pos[j-1] == '1') sum += nums[j];
                else sum -= nums[j];
            }
            stringstream out;
            if (sum == 0) {
                print(nums[0], out);
                for (int j = 1; j < nums.size(); j++) {
                    if (pos[j-1] == '1') out << '+';
                    else out << '-';
                    print(nums[j], out);
                }
                ans.pb(out.str());
            }
        }
        
        // debug, prints nums generated
        for (auto &x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
    sort(ans.begin(), ans.end());
    for (auto &x : ans) {
        fout << x << endl;
    }
    fout.close();
}