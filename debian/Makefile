prefix = /usr/local

all:
	$(CC) -o createstructure createstructure.c

install:
	gcc -o createstructure createstructure.c
	ls
	install createstructure $(DESTDIR)$(prefix)/bin
	install createstructure $(DESTDIR)$(prefix)/share/man/man1

clean:
	rm -f createstructure
