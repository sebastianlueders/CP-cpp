#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int nTests;
    scanf("%d", &nTests);

    while(nTests--) {
        int nSheep;
        scanf("%d", &nSheep);
        int minB = INT_MAX;
        int maxB = 0;

        for (int i = 0; i < nSheep; i++) {
            int currS;
            scanf("%d", &currS);

            if (currS > maxB) {
                maxB = currS;
            }

            if (currS < minB) {
                minB = currS;
            }
            
        }

        
        if (maxB == minB) {
            printf("%d\n", 1);
        } else {
            printf("%d\n", maxB - minB);
        }
        
        
        
    }

    return 0;
}
