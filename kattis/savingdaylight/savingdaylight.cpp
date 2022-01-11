#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(const string &s, char delim) {
    istringstream iss(s);
    string item;
    vector<string> ret{};
    while (getline(iss, item, delim)) {
	    ret.push_back(item);
    }
    return ret;
}

int main() {
    string line;
    vector<string> tokens;
    while (getline(cin, line)) {
        tokens = split(line, ' ');
        vector<string> starts = split(tokens[3], ':');
        vector<string> ends = split(tokens[4], ':');
        int hours;
        int minutes;
        if (stoi(ends[1]) < stoi(starts[1])) {
            hours = (stoi(ends[0])-1) - stoi(starts[0]);
            minutes = stoi(ends[1]) + 60 - stoi(starts[1]);
        } else {
            hours = stoi(ends[0]) - stoi(starts[0]);
            minutes = stoi(ends[1]) - stoi(starts[1]);
        }
        cout << tokens[0] << " " << tokens[1] << " " << tokens[2] << " ";
        cout << hours << " hours " << minutes << " minutes \n";
    }
}