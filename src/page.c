#include "page.h"

void makePage(struct pdf_doc *pdf, struct arrangement arrange) {
	pdf_append_page(pdf);

	for(int x = 0; x < arrange.itemsX; x++) {
		for(int y = 0; y < arrange.itemsY; y++) {

			uuid_t uuid;
			char uuidString[36];
			
			uuid_generate_random(uuid);
			uuid_unparse(uuid, uuidString);

			struct zint_symbol *barcode;
			barcode = ZBarcode_Create();

			barcode->symbology = BARCODE_DATAMATRIX;
			barcode->border_width = 1; //1 module quiet zone

			ZBarcode_Encode_and_Buffer(barcode, uuidString, 0, 0);

			//TODO: encode into jpeg for more efficient storage
			pdf_add_rgb24(pdf, NULL,
					x * arrange.separationX + arrange.margin,
					y * arrange.separationY + arrange.margin,
				       	arrange.sizeX, arrange.sizeY, barcode->bitmap,
					barcode->bitmap_width, barcode->bitmap_height);
		}
	}

	pdf_save(pdf, "output.pdf");
}
