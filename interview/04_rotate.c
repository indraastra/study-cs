/*
 * 04_rotate.c
 *
 *  Created on: Apr 13, 2009
 *      Author: vishal
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP_CHAR(x, y) { char _c_ = x; x = y; y = _c_; }

/*
 * Rotates a string in place using the following algorithm:
 * 
 * - Let d be the distance to be rotated clockwise.
 * - Allow the final d elements of the array to be swap space.
 * - Swap the first d elements into the last d elements.
 * - Swap the second d elements into the last d elements.
 * - Halt when starting point of nth d elements is within swap space.
 * 
 * eg: rotate by 2
 *   [x y z m n a b]
 *   => [ x y z m n | a b ]
 *   => [ a b z m n | x y ] 1st pair swapped
 *   => [ a b x y n | z m ] 2nd pair swapped
 *   => [ a b x y z | m n ] 3rd pair swapped
 *   halt because 4th pair begins inside swap
 *
 * eg: rotate by 3
 *   [x y z m n a b]
 *   => [ x y z m | n a b ] 
 *   => [ n a b m | x y z ] 1st triplet swapped
 *   => [ n a b x | y z m ] 2nd triplet swapped
 *   halt because 3rd triplet begins inside swap
 *
 */

void rotate_string(char* str, int m) {
    int len = strlen(str);
    m = m % len;
    // do nothing if m is 0
    if (m == 0) {
        return;
    }
    char* swap = str + (len - m);
    int i;
    // loop until our starting point is within the swap
    for (i = 0; i < (len - m); i += m) {
        int c;
        for (c = 0; c < m && (i + c) < len; c++) {
            //printf("swapping str[%d]:%c and swap[%d]:%c\n", i+c, str[i+c], c, swap[c]);
            SWAP_CHAR( str[i + c], swap[c] );
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Please provide a string to rotate!: ./04_rotate [STRING] [DISTANCE]\n");
        printf("eg: ./04_rotate 'abc123' 3 => 123abc\n");
        exit(-1);
    }

    char* string = argv[1];
    int distance = atoi(argv[2]);

    printf("Original: '%s'\n", string);
    rotate_string(string, distance);
	printf("Rotated: '%s'\n", string);
    return 1;
}
