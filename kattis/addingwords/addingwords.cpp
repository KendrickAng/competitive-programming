#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t last = 0;
    size_t next = 0; 
    std::vector<std::string> ret{};
    while ((next = s.find(delimiter, last)) != std::string::npos) {   
	    ret.push_back(s.substr(last, next-last));
	    last = next + 1; 
    } 
    ret.push_back(s.substr(last));
    return ret;
}

std::unordered_map<std::string, int> si{};
std::unordered_map<int, std::string> is{};

int main() {
    std::string line;
    while(std::getline(std::cin, line)) {
        std::vector<std::string> tokens = split(line, " ");
        if (tokens[0] == "def") {
            std::string name = tokens[1];
            int val = std::stoi(tokens[2]);
            // the if statement is needed to ensure we don't erase
            // the element with value 0, since si[name]
            // returns 0 if the element doesn't exist.
            if (si.find(name) != si.end()) {
                int old = si[name];
                si.erase(name);
                is.erase(old);
            }
            si[name] = val;
            is[val] = name;
        }

        if (tokens[0] == "calc") {
            // generate output string first
            std::string out = "";
            for (int i = 1; i < tokens.size()-1; i++) {
                out.append(tokens[i] + " ");
            }

            int res = 0;
            bool unknown = false;
            if (si.find(tokens[1]) != si.end()) {
                res = si[tokens[1]];
            } else {
                unknown = true;
            }

            for (int i = 2; i < tokens.size(); i+=2) {
                std::string op = tokens[i];
                if (op == "=") break;
                std::string name = tokens[i+1];
                if (si.find(name) != si.end() && op == "+") {
                    res += si[name];    
                } else if (si.find(name) != si.end() && op == "-") {
                    res -= si[name];
                } else {
                    unknown = true; break;
                }
            }
            if (is.find(res) == is.end()) {
                unknown = true;
            }

            if (unknown) {
                std::cout << out << "= " << "unknown" << std::endl;
            } else {
                std::cout << out << "= " << is[res] << std::endl;
            }
        }

        if (tokens[0] == "clear") {
            si.clear();
            is.clear();
        }
    }
}