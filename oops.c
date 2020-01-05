#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_DESCRIPTION("Oops module");
MODULE_AUTHOR("Kernel Hacker");
MODULE_LICENSE("GPL");

static noinline void do_oops(void)
{
    *(int*)0x42 = 'a';
}

static int kh_oops_init(void)
{
    pr_info("kh_oops_init\n");
    do_oops();

    return 0;
}

static void kh_oops_exit(void)
{
    pr_info("kh_oops exit\n");
}

module_init(kh_oops_init);
module_exit(kh_oops_exit);
