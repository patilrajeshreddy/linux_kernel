# target & input files

obj-m :=hello.o
obj-m +=hello_export_symbol1.o
obj-m +=hello_export_symbol2.o


# variable/macro to hold kernel-headers/kernel-source directory path

KDIR = /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean: 
	$(MAKE) -C $(KDIR) M=$(PWD) clean
