#include <bits/stdc++.h>

using namespace std;

string readAns(ifstream &ifs) {
    string ret; ifs >> ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ifstream fin("input_file", ifstream::in);
    ifstream ans("myAnswer", ifstream::in);
    ifstream cor("correctAnswer", ifstream::in);
    string myAns = readAns(ans);
    string correctAns = readAns(cor);
    if (myAns != correctAns) {
        cout << "Candidate solution found an answer, but doesn't match AC solution" << endl;
        return -1;
    }
    return 0;
}
