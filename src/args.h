#ifndef ARGS_H
#define ARGS_H

#include <stdlib.h>
#include <string.h>
#include <argp.h>
#include <pdfgen.h>

struct arguments {
	int labelSize;
	float pageX;
	float pageY;
	int margin;
};

struct arguments defaultArgs();

void parseArgs(int argc, char **argv, struct arguments *arguments);

#endif
