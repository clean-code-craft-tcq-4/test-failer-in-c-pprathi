#include <stdio.h>
#include <assert.h>

#include "tshirts.h"

//Function to determine the T-shirt sizeName based on the size in cms
char DetermineSizeName(int SizeIncms) {
    char sizeName = '\0';
    if(SizeIncms >= S_MINSIZE && SizeIncms < M_MINSIZE)
    {
        sizeName = 'S';
    }
    else if(SizeIncms >= M_MINSIZE && SizeIncms < L_MINSIZE)
    {
        sizeName = 'M';
    }
    else if(SizeIncms >= L_MINSIZE && SizeIncms < L_MAXSIZE)
    {
        sizeName = 'L';
    }
    return sizeName;
}

//Test function
void TestSizeNames(void)
{
	assert(DetermineSizeName(20) == '\0');
	assert(DetermineSizeName(37) == 'S');
	assert(DetermineSizeName(38) == 'M');
	assert(DetermineSizeName(40) == 'M');
	assert(DetermineSizeName(42) == 'L');
	assert(DetermineSizeName(43) == 'L');
	assert(DetermineSizeName(50) == '\0');
}

int main(void) {

	TestSizeNames();
    printf("All is well (maybe!)\n");
    return 0;
}
