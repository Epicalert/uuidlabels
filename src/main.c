#include <stdio.h>
#include <pdfgen.h>
#include <zint.h>
#include <uuid/uuid.h>

#include "arrange.h"

int main() {
	struct arrangement *arrange;

	arrangeGrid(PDF_A4_WIDTH, PDF_A4_HEIGHT, 144, 144, &arrange);
}
