/**********************************************************************************************
 * Defines
 *********************************************************************************************/
#define MAX_PAIR_NUMBER		25

/**********************************************************************************************
 * Enumerations
 *********************************************************************************************/
typedef enum
{
	WHITE,
	RED,
	BLACK,
	YELLOW,
	VIOLET
}MajorColor;

typedef enum
{
	BLUE,
	ORANGE,
	GREEN,
	BROWN,
	SLATE
}MinorColor;

/**********************************************************************************************
 * Structures
 *********************************************************************************************/
typedef struct {
    MajorColor majorColor;
    MinorColor minorColor;
}ColorPair;

/**********************************************************************************************
 * Function prototypes
 *********************************************************************************************/
int 	printColorMap					(void);
int 	GetPairNumberFromColor			(const ColorPair* colorPair);
void 	testPairToNumber				(MajorColor major, MinorColor minor, int expectedPairNumber);
void 	testAlignmentInPrintColorMap	(void);
int 	getMaxLenOfMajorColor			(void);
