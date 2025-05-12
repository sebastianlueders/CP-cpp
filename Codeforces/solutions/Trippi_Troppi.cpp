// TESTING: ./program < input.txt > output.txt

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
    int numLines;
    scanf("%d", &numLines);

    for (int i = 0; i <= numLines; i++) {
        string currLine;
        
        if (getline(cin, currLine)) {
            stringstream ss(currLine);
            string word;
            while (getline(ss, word, ' ')) {
                printf("%c", word[0]);
            }
        }
        if (i != 0) {
            printf("\n");
        }
        
    }
    return 0;

}
