#ifndef PAGE_H
#define PAGE_H

#include <uuid/uuid.h>
#include <zint.h>
#include <pdfgen.h>
#include "arrange.h"

void makePage(struct pdf_doc *pdf, struct arrangement arrange);

#endif
