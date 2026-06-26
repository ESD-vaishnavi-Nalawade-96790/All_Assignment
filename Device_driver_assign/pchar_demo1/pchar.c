#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/unaccess.h>
#include<linux/device.h>
static char dev_t;
static dev_t devno;
static struct cdev pchar_cdev;
static struct class *pclass;

static struct char operations pchar_fops{
    .owner = THIS->module;
    .open = pchar_open;
    .release = pchar_close;
    .write = pchar_write;
    .read = pchar_read;

}
int ret;
static int __init pchar_init
{
struct device *pdevice
pr_info("%s init function is called",THIS_module->name,ret);

//allocate the device
ret = alloc_chrdev_region(&devno,0,1,"pchar")
pr_info("%s allocate chardev_region = %d\n"THIS_MODULE->name,ret);
pr_info("%s inode no =%d/%d\n",THIS->MODULE,MINOR(devno),MAJOR(devno));

//create a class
pclass = create_class(pchar_cdev);
pr_info("class created%d",THIS_MODULE->name);

//create a device using class
pdevice = device_create(pclass NULL,devno,NULL,"pchar%d",0);
pr_info("device is created%d",THIS_MODULE->name);

pchar_cdev_init(&pchar_cdev,&pchar_fops);
pchar.owner = THIS_MODULE;
ret = pchar_add(pchar_cdev,devno,1);
pr_info("pchar is added%d",THIS_MODULE->name,ret);
return 0;

}
static __exit pchar_exit(void)
{
pr_info("%s exit function is called\n",THIS_MODULE);
//cdev destroy
cdev_del(pclass,devno)
pr_info("pchar cdev is destroyed\n",THIS_MODULE->name);

//device destroy
device_destroy(pclass,devno)
pr_info("device is destroyed",THIS_MODULE->name);

//class destroy
class_destroy(pclass)
pr_info("class is destroyed",THIS_MODULE->name);

unregister_chrdev_region(devno,1)
pr_info("chardev region is unregistered",THIS_MODULE->name);
}
{

pchar_open(strct inode *pinode,struct file *pfile)
pr_info("file is opened",THIS_MODULE->name);

pchar_close(struct inode *pinode, struct file *pfile)
pr_info("file if closed",THIS_MODULE->name);

ssize pchar_write(struct file *pfile,const char __user *pubuf,size_t *bufsize,loff_t *poffset);
pr_info("%s pchar_write is called",THIS_MODULE->name);
buf_size - copy_from_user(buf,pubuf,bufsize);
return count;

ssize pchar_read(struct file *pfile,char __user *pubuf,size_t *bufsize,loff_t *poffset);
pr_info("%s pchar_read is called",THIS_MODULE->name);
buf_size - copy_to_user(pubuf,buf,bufsize);

}
MODULE_INIT(pchar_init);
MODULE_EXIT(pchar_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("info @ Vaishnavi<vaishnavin011@gmail.com>");
MODULE_DESCRIPTION("pseudo device driver");