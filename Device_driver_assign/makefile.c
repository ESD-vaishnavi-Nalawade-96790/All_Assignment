obj-m=splitfile.o

splitfile-objs := init.o exit.o

modules:
	make -c /lib/modules/'uname -r'/build M='pwd' modules

clean:
	make -c /lib/modules/'unmae -r'/build M='pwd' clean

.phony: modules clean
