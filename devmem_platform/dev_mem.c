/**
* 说明：在使用使用驱动程序（加载驱动模块）之前，需要先加载此设备模块
**/
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/ioctl.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/platform_device.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE > KERNEL_VERSION(3, 3, 0)
        #include <asm/switch_to.h>
#else
        #include <asm/system.h>
#endif


struct platform_device memory_dev = {
 .name   = "dev_mem", //设备名称，驱动名称和设备名称需要相同
 .id    = -1,
 .dev = 
	 {
	  //.release = memory_release,
	 },
};
  
static int __init memory_dev_init(void)
{
    platform_device_register(&memory_dev); //使用platform提供的函数来注册设备

    return 0;
}

static void __exit memory_dev_exit(void)
{
    platform_device_unregister(&memory_dev); //使用platform提供的函数来注销设备
}

module_init(memory_dev_init);
module_exit(memory_dev_exit);
MODULE_LICENSE("GPL");


