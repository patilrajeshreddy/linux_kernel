/* writting a kernel module */


#include<linux/module.h> /* include for all kernel modules */
#include<linux/init.h>   /* include for all __init and __clean up modules*/


/*loading a kernel module,the init_module is called by insmod tool*/
int init_module(void)
{
        printk("%s:Module inserted\n",__func__);

	printk("HELLO WORLD\n");

        printk("dump_stack() is started in %s\n",__func__);
        
	/*stack trace for debugging*/
	dump_stack();

        printk("dump_stack() is completed in %s\n",__func__);
        
	return 0;

}


/*unloading kernel module,this cleanup_module called by the rmmod tool*/
void cleanup_module(void)
{
	printk("dump_stack() is started in %s\n",__func__);
        
	/*stack trace for debugging*/
	dump_stack();

        printk("dump_stack() is completed in %s\n",__func__);
        
	printk("%s:Module removed\n",__func__);

}


/*to write comments in binary image we use following MACRO'S*/
MODULE_AUTHOR("prr@2709");
MODULE_DESCRIPTION("LKD_CW:first kernel module");
MODULE_LICENSE("GPL");
