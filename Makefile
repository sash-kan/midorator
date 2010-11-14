
all: midorator.so

midorator.o: midorator.c midorator.h default.h midorator-entry.h midorator-history.h midorator-commands.h
	$(CC) -c $< -Iincludes -o $@ -fPIC -shared $(shell pkg-config gtk+-2.0 webkit-1.0 --cflags) $(CFLAGS)

midorator-entry.o: midorator-entry.c midorator-entry.h
	$(CC) -c $< -Iincludes -o $@ -fPIC -shared $(shell pkg-config gtk+-2.0 webkit-1.0 --cflags) $(CFLAGS)

midorator-commands.o: midorator-commands.c midorator-commands.h
	$(CC) -c $< -Iincludes -o $@ -fPIC -shared $(shell pkg-config gtk+-2.0 webkit-1.0 --cflags) $(CFLAGS)

midorator-history.o: midorator-history.c midorator-history.h
	$(CC) -c $< -Iincludes -o $@ -fPIC -shared $(shell pkg-config gtk+-2.0 webkit-1.0 sqlite3 --cflags) $(CFLAGS)

midorator.so: midorator.o midorator-entry.o midorator-history.o midorator-commands.o
	$(CC) $^ -o $@ -fPIC -shared $(shell pkg-config gtk+-2.0 webkit-1.0 sqlite3 --libs) $(LDFLAGS)

default.h: default.config
	sed 's/"/\\"/g;s/.*/\t"&",/' default.config > default.h

debug:
	$(MAKE) CFLAGS='-ggdb3 -DDEBUG -O0 -rdynamic' midorator.so

MIDORATOR_VERSION ?= 0.020101110
GIT_REV = HEAD
archive:
	git archive --prefix=midorator-$(MIDORATOR_VERSION)/ $(GIT_REV) | gzip > ../midorator_$(MIDORATOR_VERSION).orig.tar.gz
.PHONY: archive

DESTDIR =
MIDORI_LIBDIR = /usr/lib/midori/
install: all
	mkdir -p $(DESTDIR)$(MIDORI_LIBDIR)
	install midorator.so $(DESTDIR)$(MIDORI_LIBDIR)
.PHONY: install

clean:
	-rm *.o *.so
.PHONY: clean
