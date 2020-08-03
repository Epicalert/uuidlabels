#include <stdio.h>
#include <pdfgen.h>
#include <zint.h>
#include <uuid/uuid.h>

#include "arrange.h"
#include "page.h"

int main() {
	struct arrangement arrange;
	struct pdf_doc *pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, NULL);

	arrangeGrid(PDF_A4_WIDTH, PDF_A4_HEIGHT, 72, 72, &arrange);

	printf("grid size: %i x %i\n", arrange.itemsX, arrange.itemsY);
	printf("total items: %i\n", arrange.itemsX * arrange.itemsY);

	makePage(pdf, arrange);
	
	return 0;
}
