#include <stdio.h>
#include <assert.h>
#include "misaligned.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
int numberOfMajorColors =  sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors =  sizeof(minorColor) / sizeof(minorColor[0]);

int printColorMap(void) {
    int majorColorIndex = 0, minorColorIndex = 0, pairNumber = 0;
    ColorPair colorPair;
    for(majorColorIndex = 0; majorColorIndex < numberOfMajorColors; majorColorIndex++){
        for(minorColorIndex = 0; minorColorIndex < numberOfMinorColors; minorColorIndex++){
        	colorPair.majorColor = (MajorColor)majorColorIndex;
		colorPair.minorColor = (MinorColor)minorColorIndex;
		pairNumber = GetPairNumberFromColor(&colorPair);
            	printf("%-2d | %-6s | %s\n", pairNumber, majorColor[majorColorIndex], minorColor[minorColorIndex]);
        }
    }
    return majorColorIndex * minorColorIndex;
}

int GetPairNumberFromColor(const ColorPair* colorPair)
{
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor;
}

void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    assert(pairNumber == expectedPairNumber);
}

int main(void) {
    int result = printColorMap();
    assert(result == 25);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    printf("All is well (maybe!)\n");
    return 0;
}
