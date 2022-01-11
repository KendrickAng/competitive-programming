#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<char> vowels = {'a','e','i','o','u'};
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string item;
        bool first = true;
        while (getline(iss, item, ' ')) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            // begins with vowel
            if (vowels.find(item[0]) != vowels.end()) {
                item.append("yay");
                cout << item;
            } 
            // beings with consonant
            else {
                int idx = -1;
                bool hasvowel = false;
                char vowel;
                for (int i = 0; i < item.size(); i++) {
                    if (vowels.find(item[i]) != vowels.end()) {
                        vowel = item[i];
                        hasvowel = true;
                        break;
                    }
                }
                if (hasvowel) {
                    string s2 = "";
                    int idx = item.find(vowel);
                    s2.append(item.substr(idx) + item.substr(0, idx) + "ay");
                    cout << s2;
                } else {
                    cout << item + "ay";
                }
            }
        }
        cout << endl;
    }
}