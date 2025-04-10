#include <vector>
#include <cstdio>
#include <string>

using namespace std;


/*
Report all indices where P appears in T or report -1 if P cannot be found in T.
Only report starting index of the match from T and use case sensitivity.
*/


vector<int> findMatches(string T, string p) {

    const char * mainString = &T[0];
    const char * subString = &p[0];
    const char * iterPtr = subString;
    int currIndex = 0;
    int potentialIndex = 0;
    vector<int> result;

    while(*mainString) {
        if (*mainString == *iterPtr) {

            currIndex++;
            iterPtr++;
            if (!*iterPtr) {
                result.push_back(potentialIndex);
                iterPtr = subString;
                potentialIndex = currIndex;
            }


        } else {
            currIndex++;
            potentialIndex++;
        }

        mainString++;
    }

    if (result.size() == 0) result.push_back(-1);
    return result;

}

int main(int argc, char * argv[]) {

    string T = "I love CS3233 Competitive Programming. i also love ALGoRiThM";
    string P1 = "I";
    string P2 = "love";
    string P3 = "book";

    vector<int> result = findMatches(T, P1);

    printf("P1 Results: ");

    for (int i = 0; i < result.size(); i++) {
        printf(" %d", result[i]);
        if (i == result.size() - 1) {
            printf("\n");
        }
    }

    result = findMatches(T, P2);

    printf("P2 Results: ");

    for (int i = 0; i < result.size(); i++) {
        printf(" %d", result[i]);
        if (i == result.size() - 1) {
            printf("\n");
        }
    }


    result = findMatches(T, P3);

    printf("P3 Results: ");

    for (int i = 0; i < result.size(); i++) {
        printf(" %d", result[i]);
        if (i == result.size() - 1) {
            printf("\n");
        }
    }

    return 0;
    
}

