/*
 * sort.c
 *
 *  Created on: 2009-04-20

 *      Author: vishal
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SWAP_INT(x, y) { int _c_ = x; x = y; y = _c_; }

static int nums[] = {6, 7, 3, 1, 4};
static const int len = 5;

void print_array(int a[], int length) {
    int c;
    for (c = 0; c < (length - 1); c++) {
        printf("%d ", a[c]);
    }
    printf("%d\n", a[c]);
} 

bool is_sorted(int a[], int length) {
    int c;
    for (c = 0; c < (length - 1); c++) {
        if (a[c] > a[c + 1]) {
            printf("fail! %d\n", c);
            return false;
        }
    }
    return true;
}

int bubble_sort(int a[], int length) {
    int passes = 0;
    // do we make another bubbling pass through the list?
    bool repeat = false;
    // make bubble passes through the list until it is sorted
    do {
        repeat = false;
        int c;
        for (c = 0; c < (length - 1); c++) {
            if (a[c] > a[c + 1]) {
                SWAP_INT(a[c], a[c + 1]);
                repeat = true;
            }
        }
        passes++;
    } while (repeat);
    return passes;
}

int main(int argc, char* argv[]) {
    printf("Original array: ");
    print_array(nums, len);
    printf("\nSorting array...\n");
    int passes = bubble_sort(nums, len);
    if (is_sorted(nums, len)) {
        printf("Successful sort! #passes: %d\n", passes);
        printf("\nSorted array: ");
    } else {
        printf("Failed to sort!\n");
        printf("\nUnsorted array: ");
    }
    print_array(nums, len);
    
    // hack to get around terminal opening and closing in windows
    printf("\nPress any key to continue . . . ");
    getch();
}
