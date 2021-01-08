prefix = /usr/local

all:
	$(CC) -o createstructure createstructure.c

install:
	gcc -o createstructure createstructure.c
	echo $(DESTDIR)
	echo $(prefix)
	install createstructure $(DESTDIR)$(prefix)/bin
	install createstructure.1 $(DESTDIR)$(prefix)/share/man/man1

clean:
	rm -f createstructure
