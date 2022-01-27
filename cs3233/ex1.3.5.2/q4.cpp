#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    vector<int> v = {1,3,4,5};
    for (int i = 1; i <= 5; i++) v.push_back(i);
    vector<int>::iterator it = v.begin();
    cout << *it << endl;
    v.push_back(rand());
    cout << *it << endl;
}