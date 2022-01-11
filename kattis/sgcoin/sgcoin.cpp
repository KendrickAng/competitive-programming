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

    long long previousHash; cin >> previousHash;

    string transaction = "a";
    long long tmp = H(previousHash, transaction, 1);

    long long offset = (((tmp / 10000000) + 1) * 10000000) - tmp;
    long long token1 = offset+1;
    long long h1 = H(previousHash, transaction, token1);

    long long tmp2 = H(h1, transaction, 1);
    long long offset2 = (((tmp2 / 10000000) + 1) * 10000000) - tmp2;
    long long token2 = offset2 + 1;
    long long h2 = H(h1, transaction, token2);

    cout << transaction << " " << token1 << endl;
    cout << transaction << " " << token2 << endl;
    return 0;
}