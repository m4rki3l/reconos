/*
 * Copyright 2012 Daniel Borkmann <dborkma@tik.ee.ethz.ch>
 */

#include <stdio.h>
#include "sensord.h"

static void dummy_fetch(struct plugin_instance *self)
{
	printf("Hello Fetch!\n");
	self->fetch_value.dval = 1.20;
}

struct plugin_instance dummy_plugin = {
	.name		=	"dummy-1",
	.basename	=	"dummy",
	.fetch		=	dummy_fetch,
	.type		=	TYPE_FLOAT,
	.schedule_int	=	TIME_IN_SEC(1),
};

static __init int dummy_init(void)
{
	printf("Hello World!\n");
	return register_plugin_instance(&dummy_plugin);
}

static __exit void dummy_exit(void)
{
	unregister_plugin_instance(&dummy_plugin);
	printf("Goodbye World!\n");
}

plugin_init(dummy_init);
plugin_exit(dummy_exit);

PLUGIN_LICENSE("GPL");
PLUGIN_AUTHOR("Daniel Borkmann <daniel.borkmann@tik.ee.ethz.ch>");
PLUGIN_DESC("A simple dummy sensord plugin");
