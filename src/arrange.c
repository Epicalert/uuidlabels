#include "arrange.h"

void arrangeGrid(float pageWidth, float pageHeight,
		float itemWidth, float itemHeight,
		struct arrangement *arrange) {
	*arrange.itemsX = itemWidth / pageWidth;
	*arrange.itemsY = itemHeight / pageHeight;

	*arrange.separationX = itemWidth * arrange.itemsX / arrange.itemsX;
	*arrange.separationY = itemWidth * arrange.itemsY / arrange.itemsY;
}
