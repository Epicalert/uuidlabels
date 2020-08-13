#include <stdio.h>
#include <pdfgen.h>
#include <zint.h>
#include <uuid/uuid.h>

#include "arrange.h"
#include "page.h"
#include "args.h"

int main(int argc, char **argv) {
	struct arguments args = defaultArgs();
	parseArgs(argc, argv, &args);

	struct arrangement arrange;
	struct pdf_doc *pdf = pdf_create(args.pageX, args.pageY, NULL);

	arrangeGrid(args.pageX, args.pageY, args.margin,
			args.labelSize, args.labelSize, &arrange);

	printf("grid size: %i x %i\n", arrange.itemsX, arrange.itemsY);
	printf("total items: %i\n", arrange.itemsX * arrange.itemsY);

	makePage(pdf, arrange);
	
	return 0;
}
