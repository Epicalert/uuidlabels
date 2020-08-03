CFLAGS=-Ilib/pdfgen -luuid

uuidlabels: lib/pdfgen/pdfgen.o src/main.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)
