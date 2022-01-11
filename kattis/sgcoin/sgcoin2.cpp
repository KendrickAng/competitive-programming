#include <iostream>

using namespace std;

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string transaction = "a";

    // precompute table
    for (int i = 1; i <= 100; i++) {
        long long prevHash = i * 10000000;
        for (long token = 0; token < 1000000000; token++) {
            long long hash = H(prevHash, transaction, token);
            if (hash == 990000000) {
                cout << "{" << prevHash << ", " << token << "}," << endl;
                break;
            }
        }
    }

    // precompute next value for 990000000
    for (long token = 0; token < 1000000000; token++) {
        long long hash = H(990000000, transaction, token);
        if (hash / 1000000 * 1000000 == hash) {
            cout << "99000000 " << hash << " " << token << endl;
            break;
        }
    }

    return 0;
}