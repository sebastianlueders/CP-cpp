#include <bits/stdc++.h>
using namespace std;

int main(int argv, char * argc[]) {

        if (argv !=) {
                
        }

        while (1) {
                char curr;
                int pcount = 0;
                string[330] ans;
                int currN = 0;
                while (f.scanf("%c", curr) != EOF) {
                        if (pcount > -1 && curr == '.') {
                                pcount++;
                                if (pcount == 7) break;
                        }
                        if (curr != '.')        {
                                pcount = -1;
                        }
                        curr == '\n' ? ans[currN] = ' ' : ans[currN] = curr;
                        currN++;
                }

                if (pcount == 7) {
                        for (int i = 0; i < 7; i++) {
                                ans[--currN] = NaN;
                        }
                        break;
                }

                if (curr == EOF) break;
        }
}
