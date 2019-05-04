#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vl=vector<ll>;
const ll MOD = 1e9 + 7;

template<typename T>
void operator*=(vector<vl> &x, vector<vl> &y) {
int n=x.size();
vector<vl>res(n,vl(n));
for (int c=0;c<n;c++)for (int i=0;i<n;i++)for (int j=0;j<n;j++)r[i][c]=(r[i][c]+x[i][j]*y[j][c])%MOD;
x=res;
}

int main() {
    ll n;
    cin >> n;
    if (n<7){cout<<(int)(pow(2, n - 1)) << endl;return 0;}

    vector<vl>m(6);
    for (int i=5;i--;){m[0][i] = 1;if(i)m[i][i-1]=1;}
    vector<vl>r=m;
    ll p=n-7;
    while (p) {
        if (p%2)r*=m;
        p /= 2;
        mat *= mat;
    }

    ll ans = 0;
    for(ll i=0;i<6;i++)ans=(ans+(1<<(5-i))*res[0][i])%MOD;
    cout << ans << endl;
}