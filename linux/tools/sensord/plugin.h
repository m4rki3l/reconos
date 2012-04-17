/*
 * Copyright 2012 Daniel Borkmann <dborkma@tik.ee.ethz.ch>
 */

#ifndef PLUGIN_H
#define PLUGIN_H

#include <sys/time.h>

enum plugin_type {
	TYPE_SIGNED,
	TYPE_UNSIGNED,
	TYPE_FLOAT,
	TYPE_BOOL,
};

struct plugin_instance {
	char *name;                     /* unique instance name */
	char *basename;                 /* basename of plugin */
	enum plugin_type type;          /* plugin data type */
	void (*fetch)(struct plugin_instance *self);    /* callback function */
	union {
		long lval;
		unsigned long ulval;
		double dval;
		_Bool bval;
	} fetch_value;
	void *private_data;             /* plugin-private data */
	unsigned long schedule_int;     /* scheduling interval in us */
	struct timeval last;            /* last time instance called fetch */
	/* TODO: rrd descriptor */
};

#define TIME_IN_USEC(x)		(x)
#define TIME_IN_MSEC(x)		((x) * 1000)
#define TIME_IN_SEC(x)		((x) * 1000 * 1000)

extern int register_plugin_instance(struct plugin_instance *pi);
extern void unregister_plugin_instance(struct plugin_instance *pi);

#endif /* PLUGIN_H */
