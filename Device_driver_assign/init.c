#include<linux/modules.h>
static int __init split_init(void)
{

printk(KERN_INFO "%s split_init function is called\n"THIS_MODULE->name);
return 0;
}
module_init(split_init);

MODULE_LICENSE('GPL');
MODULE_AUTHOR("esd @ sunbeam");
MODULE_DESCRIPTION("this is split/muti file demo");


