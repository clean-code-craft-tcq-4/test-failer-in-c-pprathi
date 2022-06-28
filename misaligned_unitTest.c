#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "misaligned.h"

extern char buffer[100], testbuffer[100];
extern int numberOfMajorColors;
extern const char* majorColor[];

void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    assert(pairNumber == expectedPairNumber);
}

int getMaxLenOfMajorColor(void)
{
	int majorColorIndex = 0;
	int maxLen = strlen(majorColor[0]);
	for(majorColorIndex = 1; majorColorIndex < numberOfMajorColors; majorColorIndex++){
		if(strlen(majorColor[majorColorIndex]) > strlen(majorColor[0])){
			maxLen = strlen(majorColor[majorColorIndex]);
		}
	}
	return maxLen;
}

void testAlignmentInPrintColorMap(void)
{
	int i;
	for(i = 0; i< strlen(buffer); i++){
	assert(buffer[i] == testbuffer[i]);
	}
}
