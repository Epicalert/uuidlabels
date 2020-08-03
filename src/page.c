#include "page.h"

void makePage(struct pdf_doc *pdf, struct arrangement arrange) {
	pdf_append_page(pdf);

	for(int x = 0; x < arrange.itemsX; x++) {
		for(int y = 0; y < arrange.itemsY; y++) {
			pdf_add_rectangle(pdf, NULL,
					x * arrange.separationX + arrange.margin,
					y * arrange.separationY + arrange.margin,
				       	72, 72, 2, PDF_BLACK);
		}
	}

	pdf_save(pdf, "output.pdf");
}
