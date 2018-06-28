---
date: June 16, 2018
title: C++ Reference
---

# C++ Reference

I'm a Python person. C++ sucks, but it sure is better than Java. And it's solid for CP.

## Headers

```c++
#include <bits/stdc++.h>

using namespace std; // faster CP, not recommended for actual programming

typedef long long ll; // save time, defines are your friend

int main () {
    // code
}
```

## Compilation

> TODO: update Xcode to get newer versions of g++.

```
g++ -std=c++17 -O2 -Wall test.cpp -o test
```

## Stdio

```c++
// faster io
ios::sync_with_stdio(0);
cin.tie(0);

string s;
cin >> s;
cout << s << endl;

// or, C-style
char tmp[101];
scanf("%100s", tmp); // scanf doesn't support C++ data structures, but saves time
string s = tmp;

printf("%s\n", s);

getline(cin, s); // get spaces etc.

while (cin >> x) {
    // for each input
}

// file io
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

## Data structures

```c++
int a = 0;
long long a = 1000000000000;

string s = "Hello world"; //std::string
vector <string, int> ages;
ages.push_back(make_pair("Aryaman", 15));

struct Human {
    string given_name, surname;
    int age;
    Human mother, father;
    vector<Human> siblings;
};
```