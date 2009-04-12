#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// macro from
// > www.den.rcast.u-tokyo.ac.jp/~suzuki/class/infosys/programs/reverse.c
#define SWAP_CHAR(x, y) { char c; c = x; x = y; y = c; }

// in-place substring reversal
void reverse_substring(char* str, int start_idx, int end_idx) {
    // loop from outside in; meet at the middle
    for (start_idx; start_idx < end_idx; start_idx++, end_idx--) {
        // swap characters
        SWAP_CHAR(str[start_idx], str[end_idx]);
    }
}

// in-place string reversal
void reverse_string(char* str) {
    reverse_substring(str, 0, strlen(str));
}

// in-place word order reversal
void reverse_words(char* str) {
    int len = strlen(str);
    reverse_substring(str, 0, len - 1);
    // loop through words and reverse words
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            if (str[j] == ' ') {
                reverse_substring(str, i, j - 1);
                i = j;
                break;
            }
        }
        // at this point, j has hit the end of the string so we know we're at
        // the last word; we reverse it directly and break the outer loop
        if (j == len) {
            reverse_substring(str, i, len - 1);
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide a string whose words you wish to put in reverse order!\n");;
        exit(-1);
    }

    char* string = argv[1];
    printf("Original: %s\n", string);
    reverse_words(string);
    printf("Word-order reversed: %s\n", string);
}
