#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "misaligned.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
int numberOfMajorColors =  sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors =  sizeof(minorColor) / sizeof(minorColor[0]);
char buffer[100], testbuffer[100];

int printColorMap(void) {
    int majorColorIndex = 0, minorColorIndex = 0, pairNumber = 0, maxLen = 0, len = 0;
    char str[10];
    ColorPair colorPair;
    maxLen = getMaxLenOfMajorColor(); 				//get max string length from majorColor list
	sprintf(str,"%d",MAX_PAIR_NUMBER);
	len = strlen(str);								// get the max string length of max pair number

    for(majorColorIndex = 0; majorColorIndex < numberOfMajorColors; majorColorIndex++){
        for(minorColorIndex = 0; minorColorIndex < numberOfMinorColors; minorColorIndex++){
        	colorPair.majorColor = (MajorColor)majorColorIndex;
			colorPair.minorColor = (MinorColor)minorColorIndex;
			pairNumber = GetPairNumberFromColor(&colorPair);
			sprintf(buffer, "%-2d | %-6s | %s\n", pairNumber, majorColor[majorColorIndex], minorColor[minorColorIndex]);
			printf("%s", buffer);
			sprintf(testbuffer, "%-*d | %-*s | %s\n", len, pairNumber, maxLen, majorColor[majorColorIndex], minorColor[minorColorIndex]);
		}
    }
    return majorColorIndex * minorColorIndex;
}

int GetPairNumberFromColor(const ColorPair* colorPair)
{
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}

int main(void) {
    assert(printColorMap() == 25);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    testAlignmentInPrintColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
