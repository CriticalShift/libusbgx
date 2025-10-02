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

#ifndef USBG_FUNCTION_ACCESSORY__
#define USBG_FUNCTION_ACCESSORY__

#include <usbg/usbg.h>

#ifdef __cplusplus
extern "C" {
#endif

struct usbg_f_accessory;
typedef struct usbg_f_accessory usbg_f_accessory;

/**
 * @brief Convert from generic function to an accessory function
 * @param[in] f function to be converted to an accessory function.
 *         Function should be of type function accessory.
 * @return Converted function or NULL if function hasn't suitable type
 */
usbg_f_accessory *usbg_to_accessory_function(usbg_function *f);

/**
 * @brief Convert from accessory function to a generic one
 * @param[in] ac function to be converted to generic one
 * @return Generic usbg function
 */
usbg_function *usbg_from_accessory_function(usbg_f_accessory *ac);

#ifdef __cplusplus
}
#endif

#endif /* USBG_FUNCTION_ACCESSORY__ */
