/* basic kernel program for understanding EXPORT_SYMBOL_GPL() */

#include<linux/module.h>
#include<linux/init.h>

/* this function exporting */
void func(void)
{
        printk("%s:Hello world\n",__func__);
}


int mod_init(void)
{
        printk("%s:Module inserted\n",__func__);

        return 0;
}

void mod_exit(void)
{
        printk("%s:Module removed\n",__func__);

}

/* following are macros for the init() and exit() */
module_init(mod_init);
module_exit(mod_exit);

/*EXPORT_SYMBOL_GPL(func) here we are exporting the funct() logic  present inthis module to another module*/
EXPORT_SYMBOL_GPL(func);

MODULE_AUTHOR("prr@2709");
MODULE_DESCRIPTION("LKD_CW:Exporting a module");
MODULE_LICENSE("GPL");
