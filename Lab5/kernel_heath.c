#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init init_hello(void) {
	printk("Heath: Hello, Kernel! I'm Heath Kim, aka Kim Sang Hee!\n");
	printk("Heath: Current linux version is Ubuntu 16.04!\n And kernel version is 4.9.70!\n");

	return 0;
}

static void __exit exit_hello(void) {
	printk("Heath: Good bye, Kernel! See you next time!\n");
}

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
