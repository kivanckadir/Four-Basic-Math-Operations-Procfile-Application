#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x15b2dc7b, "module_layout" },
	{ 0x29b50afb, "remove_proc_entry" },
	{ 0xe95b852a, "create_proc_entry" },
	{ 0xcdb642f5, "proc_mkdir" },
	{ 0x91715312, "sprintf" },
	{ 0x50eedeb8, "printk" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "35F0B02BFE622F6585942A7");
