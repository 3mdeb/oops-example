#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_DESCRIPTION("Oops module");
MODULE_AUTHOR("Kernel Hacker");
MODULE_LICENSE("GPL");

static noinline void do_oops(void)
{
    *(int*)0x42 = 'o';
}

static int kh_oops_init(void)
{
    pr_debug("dbg: kh_oops_init before do_oops\n");
    pr_info("kh_oops_init\n");
    //do_oops();
    pr_debug("dbg: kh_oops_init after do_oops\n");

    return 0;
}

static void kh_oops_exit(void)
{
    pr_debug("dbg: kh_oops_exit 1\n");
    pr_info("kh_oops_exit\n");
    pr_debug("dbg: kh_oops_exit 2\n");
}

module_init(kh_oops_init);
module_exit(kh_oops_exit);
