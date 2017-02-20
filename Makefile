all:
	gcc dns-add.c -o dns-add
clean:
	rm dns-add
install:
	cp dns-add /usr/local/bin/dns-add
remove:
	rm /usr/local/bin/dns-add
	$(info You still have to remove the config files...)
