/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */

#include "usbg/usbg.h"
#include "usbg/usbg_internal.h"
#include "usbg/function/accessory.h"

#ifdef HAS_GADGET_SCHEMES
#include <libconfig.h>
#endif

struct usbg_f_accessory {
	struct usbg_function func;
};

GENERIC_ALLOC_INST(accessory, struct usbg_f_accessory, func)

GENERIC_FREE_INST(accessory, struct usbg_f_accessory, func)

static int accessory_set_attrs(struct usbg_function *f, void *f_attrs)
{
	return USBG_SUCCESS;
}

static int accessory_get_attrs(struct usbg_function *f, void *f_attrs)
{
	return USBG_SUCCESS;
}

static int accessory_libconfig_import(struct usbg_function *f,
				  config_setting_t *root)
{
	return USBG_SUCCESS;
}

static int accessory_libconfig_export(struct usbg_function *f,
				  config_setting_t *root)
{
	return USBG_SUCCESS;
}

/* We don't import nor export port_num as it is read only */
#define ACCESSORY_FUNCTION_OPTS			\
	.alloc_inst = accessory_alloc_inst,	\
	.free_inst = accessory_free_inst,	        \
	.set_attrs = accessory_set_attrs,	        \
	.get_attrs = accessory_get_attrs,	        \
	.export = accessory_libconfig_export,	\
	.import = accessory_libconfig_import

struct usbg_function_type usbg_f_type_accessory = {
	.name = "accessory",
	ACCESSORY_FUNCTION_OPTS,
};

/* API implementation */

usbg_f_accessory *usbg_to_accessory_function(usbg_function *f)
{
	return f->ops == &usbg_f_type_accessory ?
		container_of(f, struct usbg_f_accessory, func) : NULL;
}

usbg_function *usbg_from_accessory_function(usbg_f_accessory *sf)
{
	return &sf->func;
}
