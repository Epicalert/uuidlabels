#include <stdio.h>
#include "arrange.h"

void arrangeGrid(float pageWidth, float pageHeight,
		float itemWidth, float itemHeight,
		struct arrangement *arrange) {
	arrange->itemsX = (int)(pageWidth / itemWidth);
	arrange->itemsY = (int)(pageHeight / itemHeight);


	arrange->separationX = (pageWidth - (itemWidth * arrange->itemsX)) / arrange->itemsX + itemWidth;
	arrange->separationY = (pageHeight - (itemHeight * arrange->itemsY)) / arrange->itemsY + itemHeight;
}
