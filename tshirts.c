#include <stdio.h>
#include <assert.h>

#include "tshirts.h"

//Function to determine the T-shirt sizeName based on the size in cms
char DetermineSizeName(int SizeIncms) {
    char sizeName = '\0';
    if(SizeIncms < M_MINSIZE)
    {
        sizeName = 'S';
    }
    else if(SizeIncms > M_MINSIZE && SizeIncms < L_MINSIZE)
    {
        sizeName = 'M';
    }
    else
    {
        sizeName = 'L';
    }
    return sizeName;
}

int main(void) {
    assert(DetermineSizeName(37) == 'S');
    assert(DetermineSizeName(38) == 'M');
    assert(DetermineSizeName(40) == 'M');
    assert(DetermineSizeName(42) == 'L');
    assert(DetermineSizeName(43) == 'L');

    printf("All is well (maybe!)\n");
    return 0;
}
