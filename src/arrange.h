#ifndef ARRANGE_H
#define ARRANGE_H

//holds information for arranging the images in a grid pattern
struct arrangement {
	int itemsX;		//number of items that can fit on the page
	int itemsY;		//number of items that can fit on the page
	float separationX;	//space between items on X (including item size)
	float separationY;	//space between items on Y (including item size)
};

void arrangeGrid(float pageWidth, float pageHeight,
		float itemWidth, float itemHeight,
		struct arrangement *arrange);
#endif
