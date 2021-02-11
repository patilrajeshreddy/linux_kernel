/* we are using func() logic present in the another module */

#include<linux/module.h>
#include<linux/init.h>

/* telling that func() logic present in another modules */
extern void func(void);

int mod_init(void)
{
        //printk("%s:Module inserted\n",__func__);

        func();

        return 0;
}

void mod_exit(void)
{
        //printk("%s:Module removed\n",__func__);

}

module_init(mod_init);
module_exit(mod_exit);

MODULE_AUTHOR("support@techvead.org");
MODULE_DESCRIPTION("LKD_CW:first kernel module");
MODULE_LICENSE("GPL");

