PREFIX = /usr/local

dmenu-recent-aliases: ;

.PHONY: install
install: dmenu-recent-aliases
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 4755 -o root $< $(DESTDIR)$(PREFIX)/bin

.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dmenu-recent-aliases
