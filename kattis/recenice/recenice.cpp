#include <bits/stdc++.h>

using namespace std;

string translate1(string num) {
    unordered_map<string,string> trans = {
        {"0", ""},
        {"1", "one"},
        {"2", "two"},
        {"3", "three"},
        {"4", "four"},
        {"5", "five"},
        {"6", "six"},
        {"7", "seven"},
        {"8", "eight"},
        {"9", "nine"},
    };
    return trans[num];
}

string translate2(string num) {
    if (num[0] == '0') return translate1(num.substr(1));

    unordered_map<string,string> trans = {
        {"10", "ten"},
        {"11", "eleven"},
        {"12", "twelve"},
        {"13", "thirteen"},
        {"14", "fourteen"},
        {"15", "fifteen"},
        {"16", "sixteen"},
        {"17", "seventeen"},
        {"18", "eighteen"},
        {"19", "nineteen"},
    };

    if (trans.find(num) != trans.end()) return trans[num];

    if (num[0] == '2') return "twenty" + translate1(num.substr(1));
    if (num[0] == '3') return "thirty" + translate1(num.substr(1));
    if (num[0] == '4') return "forty" + translate1(num.substr(1));
    if (num[0] == '5') return "fifty" + translate1(num.substr(1));
    if (num[0] == '6') return "sixty" + translate1(num.substr(1));
    if (num[0] == '7') return "seventy" + translate1(num.substr(1));
    if (num[0] == '8') return "eighty" + translate1(num.substr(1));
    if (num[0] == '9') return "ninety" + translate1(num.substr(1));

    return "";
}

string translate3(string num) {
    if (num.size() == 3) {
        return translate1(num.substr(0,1)) + "hundred" + translate2(num.substr(1));
    } else if (num.size() == 2) {
        return translate2(num);
    } else {
        return translate1(num);
    }
}

int main() {
    int n; cin >> n; cin.ignore();

    string line;
    string answer = "";
    int letters = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        if (line != "$") {
            letters += line.size();
        }
        answer += (line + " ");
    }
    answer.pop_back();

    for (int i = 1; i < 1000; i++) {
        string s = translate3(to_string(i));
        if (i == letters + s.size()) {
            answer.replace(answer.find('$'), 1, s);
            break;
        }
    }

    cout << answer << endl;
}