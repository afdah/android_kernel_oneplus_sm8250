#ifndef __KSU_H_KLOG
#define __KSU_H_KLOG

#include <linux/printk.h>

#ifdef pr_fmt
#undef pr_fmt
#define pr_fmt(fmt) "KernelSU: " fmt
#endif

/* Stealth: silence KSU informational dmesg noise by default.
 * Demote pr_info -> pr_debug (compiled out unless dynamic_debug is enabled
 * or CONFIG_KSU_DEBUG=y). pr_warn/pr_err stay visible. */
#ifndef CONFIG_KSU_DEBUG
#undef pr_info
#define pr_info(fmt, ...) pr_debug(fmt, ##__VA_ARGS__)
#endif

#endif
