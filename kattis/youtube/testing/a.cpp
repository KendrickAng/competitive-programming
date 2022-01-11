#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 5;
int a[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n);
    printf("%d\n", a[2]);
    assert(false && "you are WEON");
}