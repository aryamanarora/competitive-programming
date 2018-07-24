# Vectors

Vectors are dynamic arrays. They can be resized with `vector.resize(n)`.

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> vec{3, 2, 9, 1, -1};

    // access elements
    cout << *vec.begin() << " == " << vec[0] << " == " << vec.at(0) << endl;

    // adding new elements to back
    vec.push_back(3);

    // removing elements
    vec.erase(vec.begin() + 2);

    // sorting
    sort(vec.begin(), vec.end()); // small to big
    sort(vec.rbegin(), vec.rend()); // big to small

    // shuffle
    random_shuffle(vec.begin(), vec.end());

    // get unique elements of vector
    vec.erase(unique(vec.begin(), vec.end()));
}
```