CFLAGS=-Ilib/pdfgen -luuid -lzint
OBJS=lib/pdfgen/pdfgen.o src/main.o src/arrange.o src/page.o

uuidlabels: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	$(RM) $(OBJS) uuidlabels
