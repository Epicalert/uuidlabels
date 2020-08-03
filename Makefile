CFLAGS=-Ilib/pdfgen -luuid

uuidlabels: lib/pdfgen/pdfgen.o src/main.o src/arrange.o src/page.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)
