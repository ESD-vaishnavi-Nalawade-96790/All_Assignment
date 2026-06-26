#include<linux/module.h>
#include<linux/timer.h>

struct timer_list mytimer;

int count = 0;
int ticks = 0;

void mytimer_handler(struct timer_list *timer)
{
	printk(KERN_INFO "%s : count = %d\n",THIS_MODULE->name,count);

	count++;
	mod_timer(&mytimer, jiffies + ticks);
}
static int __init esd_init(void)
{
	int sec = 3;
	ticks = sec * HZ;

	timer_setup(&mytimer,mytimer_handler,0);



}
