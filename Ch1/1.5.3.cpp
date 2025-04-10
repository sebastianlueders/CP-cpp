#include <vector>
#include <string>
#include <cstdio>
using namespace std;

/*
Determine the number of consonants and vowels there are in T while
transforming T to all lowercase.
*/


int main() {
    
    string T = "I love CS3233 Competitive Programming. i also love ALGoRiThM";
    printf("Original String: %s\n", T.c_str());
    int i = 0;
    int cons = 0;
    int vows = 0;

    while(i < T.size()) {
        int current = (int) T[i];

        if (current > 64 && current < 91) {
            T[i] = (char) current + 32;
        }

        current = T[i];

        if (current > 96 && current < (96 + 26 + 1)) {
            if (current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u') {
                vows++;
            } else {
                cons++;
            }
        }
        i++;

    }

    printf("Lowercase String: %s\n", T.c_str());
    printf("Number of Consonants: %d\n", cons);
    printf("Number of Vowels: %d\n", vows);

}