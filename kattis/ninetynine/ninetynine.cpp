#include <iostream>

using namespace std;

int main() {
    int fr = 0;
    int me = 1;
    cout << me << endl;
    while (cin >> fr) {
        if (fr == 99) exit(0);
        
        if (fr % 3 == 0) {
            me = fr + 2;
        } else if ((fr + 1) % 3 == 0) {
            me = fr + 1;
        } else if ((fr + 2) % 3 == 0) {
            me = fr + 2;
        }

        cout << me << endl;
        if (me >= 99) exit(0);
    }
}