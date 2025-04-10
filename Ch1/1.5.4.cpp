#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


/*
Tokenize T into an array of strings and then sort lexographically
*/


int main() {
    string T = "i love cs3233 competitive programming. i also love algorithm";
    istringstream iss(T);
    string token;
    vector<string> tokens;

    while (iss >> token) {
        tokens.push_back(token);
    }

    sort(tokens.begin(), tokens.end());

    for (int i = 0; i < tokens.size(); i++) {
        printf("%s\n", tokens[i].c_str());
    }

}