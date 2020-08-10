#include <stdio.h>
#include "arrange.h"

void arrangeGrid(float pageWidth, float pageHeight, float margin,
		float itemWidth, float itemHeight,
		struct arrangement *arrange) {
	float usablePageWidth = pageWidth - margin * 2;
	float usablePageHeight = pageHeight - margin * 2;

	arrange->itemsX = (int)(usablePageWidth / itemWidth);
	arrange->itemsY = (int)(usablePageHeight / itemHeight);

	arrange->separationX = (usablePageWidth - (itemWidth * arrange->itemsX)) / arrange->itemsX + itemWidth;
	arrange->separationY = (usablePageHeight - (itemHeight * arrange->itemsY)) / arrange->itemsY + itemHeight;

	arrange->sizeX = itemWidth;
	arrange->sizeY = itemHeight;

	arrange->margin = margin;
}
