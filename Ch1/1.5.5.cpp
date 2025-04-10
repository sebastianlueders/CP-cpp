#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;


/*
Determine the highest frequency word in T
*/

int main() {
    string T = "i love cs3233 competitive programming. i also love algorithm";

    unordered_map<string, int> freq;

    istringstream iss(T);
    string token;
    vector<string> tokens;

    while (iss >> token) {
        tokens.push_back(token);
        freq[token]++;
    }


    string mostFreq;
    int maxCount = 0;

    for (auto& pair : freq) {
        if (pair.second > maxCount) {
            mostFreq = pair.first;
            maxCount = pair.second;
        }
    }

    printf("The most frequent word was %s which showed up %d times!", mostFreq.c_str(), maxCount);


}