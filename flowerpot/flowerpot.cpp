#include "pch.h"
#include <iostream>
#include "flowerpot.h"

int onesMaskOfWidthLength(int width)
{
	return pow(2, width) - 1;
}

int horizontalFlow(int whereIsWater, int lowerRow, int width)
{
	int rowAfterSpreading = 0;
	if (whereIsWater != lowerRow)	// check if it can spread anywhere
	{
		int noOfLoops = width;
		while (rowAfterSpreading != whereIsWater && --noOfLoops > 0)			// if water didnt spread in previous loop stop
		{
			if (noOfLoops != width - 1)
				whereIsWater |= rowAfterSpreading;								// update where is water in a row
			rowAfterSpreading |= (whereIsWater >> 1) & lowerRow;				// spread to right
			rowAfterSpreading |= (whereIsWater << 1) & lowerRow;				// spread to left
		}
	}
	else
		return whereIsWater;
	return rowAfterSpreading | whereIsWater;									// binary sum because if water didn't spread anywhere it still dropped somewhere
}

bool canWaterFlow(int flowerpot, int width, int depth)
{
	int upperRow = flowerpot & onesMaskOfWidthLength(width);
	for (int i = 1; i < depth; ++i)
	{
		// droping the water down and spreading it, then updating upperRow with next one
		flowerpot = flowerpot >> width;
		upperRow = horizontalFlow(upperRow & flowerpot, flowerpot & onesMaskOfWidthLength(width), width);
	}
	if (upperRow != 0)
		return true;
	return false;
}