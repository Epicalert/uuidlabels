#include "args.h"
#include <stdio.h>

//TODO: add margin
static struct argp_option options[] = {
	{"label-size",	's',	"pt",	0,	"Size of each label in pt"},
	{"page-size",	'p',	"size",	0,	"Size of the page (A4, Letter)"},
	{0}
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
	struct arguments *arguments = state->input;

	switch(key) {
		case 's':
			arguments->labelSize = atoi(arg);
			break;
		case 'p':
			//TODO: make code less bad
			if (strcasecmp(arg,"A4") == 0) {
				printf("a4!\n");
				arguments->pageX = PDF_A4_WIDTH;
				arguments->pageY = PDF_A4_HEIGHT;
			} else if (strcasecmp(arg,"Letter") == 0) {
				printf("letter!\n");
				arguments->pageX = PDF_LETTER_WIDTH;
				arguments->pageY = PDF_LETTER_HEIGHT;
			}
			break;
			
		case ARGP_KEY_END:
			break;

		default:
			return ARGP_ERR_UNKNOWN;
	}

	return 0;
}

struct argp argp = {options, parse_opt, 0, 0};

struct arguments defaultArgs() {
	struct arguments arguments;

	arguments.labelSize = 72;
	arguments.pageX = PDF_A4_WIDTH;
	arguments.pageY = PDF_A4_HEIGHT;

	return arguments;
}

void parseArgs(int argc, char **argv, struct arguments *arguments) {
	argp_parse(&argp, argc, argv, 0, 0, arguments);
}
