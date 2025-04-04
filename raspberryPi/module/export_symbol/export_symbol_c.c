#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

extern void export_symbol_test_func1(void);
extern void export_symbol_test_func2(void);


static int export_symbol_c_init(void)
{
    printk(KERN_INFO "export symbol c init\n");
    export_symbol_test_func1();
    export_symbol_test_func2();
    return 0;
}

static int export_symbol_c_exit(void)
{
    printk(KERN_INFO "export symbol c exit\n");
    return 0;
}

module_init(export_symbol_c_init);
module_exit(export_symbol_c_exit);
MODULE_LICENSE("Proprietary");

