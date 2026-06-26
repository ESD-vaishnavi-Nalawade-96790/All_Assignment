#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/cdev.h>

static struct file_operations pchar_fops =
{
	.owner = THIS_MODULE,
	.open = pchar_open,
	.release = pchar_close,
	.read = pcahr_read,
	.write = pchar_write


};

static int __init pchar_init(void){

	int ret;
	struct device *pdevice;
	pr_info("%s: pchar_init() called.\n",THIS_MODULE->name);
	ret = alloc_chrdev_region(&devno,0,1,"pchar");
	pr_info("%s: alloc_chrdev_region() returned=%d.\n",THIS_MODULE->name,ret);
	pr_info("%s: device number = %d/%d.\n",THIS_MODULE_->name,MAJOR(devno), MINOR(devno));
	pclass = class_create(THIS_MODULE,"pchar_class");
	pr_info("%s: device_create() created device class.\n",THIS_MODULE->name);
	pdevice = device_create(pclass,NULL,devno,NULL,"pchar%d",0);
	pr_info("%s: device_create() created device file.\n",THIS_MODULE->name);

	cdev_init(&pchar_cdev,&pchar_fops);
	pchar_cdev.owner = THIS_MODULE;
	ret = cdev_add(&pchar_cdev,devno,1);
	pr_info("%s: cdev_add() added cdev in karnel & returned =%d\n",THIS_MODULE->name,ret);
	return 0;

}
