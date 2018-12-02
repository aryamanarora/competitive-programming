#include <bits/stdc++.h>

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "abcd";
    do {
        cout << s << endl;
    }
    while (next_permutation(s.begin(), s.end()));

    char n;
    cin >> n;
    for (char i = 'a'; i <= n; i++) cout << i;
    char last = 'b';
    for (int i = 0; i <= (n - 'a') - 2; i++) {
        cout << "a";
        for (char j = 0; j <= (n - 'a') - 2; j++) {
            cout << last;
            last++;
            if (last == n + 1) last = 'b';
        }
    }
    cout << "ac" << endl;
}

/*
USE LONG LONG!!!!

```
abcd a bc a db a c

abcdabcadbac
------------
abcd
ab d  c
a c  b  d
a cd b
a  d bc
a  d  c  b
 b  a c d
 b  a   d  c
 bc a   d
 bcda
 b da c
 b d  ca
  c ab  d
  c a   db
  c  b ad
  c  b  d a
  cdab
  cd b a
   dabc
   da c  b
   d b a   c
   d bca
   d  ca b
   d  c  ba
*/