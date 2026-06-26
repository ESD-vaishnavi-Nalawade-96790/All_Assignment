#include<linux/module.h>
static void __exit split_exit(void)
{
	printk(KERN_MODULE"%sThis the exit is called\n"THIS_MODULE->name);

}
MODULE_exit(split_exit);
