#include <bits/stdc++.h>
using namespace std;

/*
Reads file name specified at runtime and finds the first instance of 7 consecutive periods
at the beginning of a line, returning a concatenated of all following characters and 
seperated by spaces between newlines in the file.
*/


#define MAX_LINE_LEN 30
#define MAX_NUM_LINES 10
#define TARGET_PER 7

int main(int argc, char * argv[]) {

        if (argc < 2) {
                printf("Must pass filename to read!");
                return -1;
        }
        if (argc > 2) {
                printf("Passing more than just the filename is beyond this program's scope.");
                return -1;
        }

        ifstream file;
        file.open(argv[1]);

        string currLine;
        int final = 0;
        int numPeriods;
        char ret_str[MAX_LINE_LEN * MAX_NUM_LINES];
        int ret_itr = 0;
        int line_itr = 0;

        while(getline(file, currLine)) {
                int char_itr = 0;
                char curr_char = currLine[char_itr];
                numPeriods = 0;
                if (!final) {
                        while (curr_char == '.') {
                                numPeriods++;

                                curr_char = currLine[++char_itr];
                                
                                if (numPeriods == TARGET_PER) {
                                        final = 1;
                                        while (curr_char) {
                                                ret_str[ret_itr++] = curr_char;
                                                curr_char = currLine[++char_itr];
                                        }
                                }
                        }
                } else {
                        ret_str[ret_itr++] = ' ';
                        while(curr_char) {
                                ret_str[ret_itr++] = curr_char;
                                curr_char = currLine[++char_itr];
                        }
                }

        }
        
        for(int i = 0; i < ret_itr; i++) {
                printf("%c", ret_str[i]);
        }
        printf("\n");

        return 0;
}
