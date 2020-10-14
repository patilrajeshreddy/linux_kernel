# target & input files

obj-m :=hello.o

# variable/macro to hold kernel-headers/kernel-source directory path

KDIR = /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean: 
	$(MAKE) -C $(KDIR) M=$(PWD) clean
