#ifndef ARRANGE_H
#define ARRANGE_H

//TODO: add item size to arrangement
//holds information for arranging the images in a grid pattern
struct arrangement {
	int itemsX;		//number of items that can fit on the page
	int itemsY;		//number of items that can fit on the page
	float separationX;	//space between items on X (including item size)
	float separationY;	//space between items on Y (including item size)
	float sizeX;		//size of one item on X
	float sizeY;		//size of one item on Y
	float margin;		//page margin
};

void arrangeGrid(float pageWidth, float pageHeight, float margin,
		float itemWidth, float itemHeight,
		struct arrangement *arrange);
#endif
